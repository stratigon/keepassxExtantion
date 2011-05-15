/**********************************************************\

  Auto-generated keepassxExtantionAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"

#include "keepassxExtantionAPI.h"

///////////////////////////////////////////////////////////////////////////////
/// @fn keepassxExtantionAPI::keepassxExtantionAPI(const keepassxExtantionPtr& plugin, const FB::BrowserHostPtr host)
///
/// @brief  Constructor for your JSAPI object.  You should register your methods, properties, and events
///         that should be accessible to Javascript from here.
///
/// @see FB::JSAPIAuto::registerMethod
/// @see FB::JSAPIAuto::registerProperty
/// @see FB::JSAPIAuto::registerEvent
///////////////////////////////////////////////////////////////////////////////
keepassxExtantionAPI::keepassxExtantionAPI(const keepassxExtantionPtr& plugin, const FB::BrowserHostPtr& host) : m_plugin(plugin), m_host(host)
{
    registerMethod("echo",			make_method(this, &keepassxExtantionAPI::echo));
    registerMethod("testEvent",		make_method(this, &keepassxExtantionAPI::testEvent));
    registerMethod("add",			make_method(this, &keepassxExtantionAPI::add));
	registerMethod("getUrls",		make_method(this, &keepassxExtantionAPI::getUrls));
	registerMethod("getAccount",	make_method(this, &keepassxExtantionAPI::getAccount));
	
	
    // Read-write property
    registerProperty("testString",
                     make_property(this,
                        &keepassxExtantionAPI::get_testString,
                        &keepassxExtantionAPI::set_testString));

    // Read-only property
//    registerProperty("param",
//                     make_property(this,
//								   &keepassxExtantionAPI::get_param));
	registerProperty("version",
                     make_property(this,
								   &keepassxExtantionAPI::get_version));
    
	keepassxExtantionAPI::init();
	
    registerEvent("onfired");    
}

///////////////////////////////////////////////////////////////////////////////
/// @fn keepassxExtantionAPI::~keepassxExtantionAPI()
///
/// @brief  Destructor.  Remember that this object will not be released until
///         the browser is done with it; this will almost definitely be after
///         the plugin is released.
///////////////////////////////////////////////////////////////////////////////
keepassxExtantionAPI::~keepassxExtantionAPI()
{
	SecString::deleteSessionKey();
}

///////////////////////////////////////////////////////////////////////////////
/// @fn keepassxExtantionPtr keepassxExtantionAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
keepassxExtantionPtr keepassxExtantionAPI::getPlugin()
{
    keepassxExtantionPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}



void keepassxExtantionAPI::init(){
	
	// Initialize the locale environment.
	db = new Kdb3Database();
	dbReadOnly = false;

	
	initYarrow(); //init random number generator
	SecString::generateSessionKey();
	
	
}


// Read/Write property testString
std::string keepassxExtantionAPI::get_testString()
{
    return m_testString;
}
void keepassxExtantionAPI::set_testString(const std::string& val)
{
    m_testString = val;
}

// Read-only property version
std::string keepassxExtantionAPI::get_version()
{
    return "CURRENT_VERSION";
}

// Method echo
FB::variant keepassxExtantionAPI::echo(const FB::variant& msg)
{
    return msg;
}


void keepassxExtantionAPI::testEvent(const FB::variant& var)
{
    FireEvent("onfired", FB::variant_list_of(var)(true)(1));
}

long keepassxExtantionAPI::add(long a, long b, long c)
{
	long t = 2*(a+b+c);
	return t;
}

//FB:variant keepassxExtantionAPI::get_param(int dd)
//{
//	return getPlugin()->m_params["data"];
//	//return getPlugin()->getParam("data");
//}

//! Connector to kdb database
int keepassxExtantionAPI::openDatabase(std::string filename, SecString* secPass)
{	

	// This implementation don't provide key file
	QString keyfile = "";
	secPass->unlock();
	db->setKey(secPass->string(), keyfile);
	secPass->lock();

	
	if(!filename.empty()){
		QString qFilename = QDir::cleanPath( QString::fromStdString(filename) );
		
		if (QFile::exists(qFilename)){
			if (!QFile::exists(qFilename+".lock")){
				
				if (!dbReadOnly && !QFile::exists(qFilename+".lock")){
					QFile lock(qFilename+".lock");
					if (!lock.open(QIODevice::WriteOnly)){
						dbReadOnly = true;
					}
				}
				
				
				if(db->load(qFilename, dbReadOnly)){
					return 0;
				}
				else {
					keepassxExtantionAPI::kpxErrorMsg = "kpx_error: Can't load database file (error on device or in DB structure)";
					return 5;
				}

			}
			else {
				keepassxExtantionAPI::kpxErrorMsg = "kpx_error: Database file is locked";
				return 4;
			}

		}
		else {
			keepassxExtantionAPI::kpxErrorMsg = "kpx_error: File doesn't exist";
			return 3;
		}
		
	}
	else {
		keepassxExtantionAPI::kpxErrorMsg = "kpx_error: File name is empty";
		return 2;
	}
	
	keepassxExtantionAPI::kpxErrorMsg = "kpx_error: Unexpected error";
	return 1;
}

int keepassxExtantionAPI::closeDatabase(std::string filename){
	
	db->close();
	
	
	delete db;
	db=NULL;
	
	
	QString qFilename = QDir::cleanPath( QString::fromStdString(filename));
	
	if (!dbReadOnly && QFile::exists(qFilename+".lock")){
		if (!QFile::remove(qFilename+".lock"))
			keepassxExtantionAPI::kpxErrorMsg = "kpx_error: Couldn't remove database lock file.";
			return 1;
	}
	
	return 0;
}



// Return a UTF8  string with JSON array
std::string keepassxExtantionAPI::getUrls(std::string filename, std::string openPass){
	
	keepassxExtantionAPI::init();
	
	SecString secPass;
	QString tmpPass = QString::fromStdString(openPass);
	// owerwrite openPass
	if( openPass.size() )
		for(int i=0; i<openPass.size(); i++)
			openPass[i]=0;
	// set secPass and owerwrite tmpPass
	secPass.setString(tmpPass, true);
	
	
	// Try open database
	dbReadOnly = true;
	if(keepassxExtantionAPI::openDatabase(filename, &secPass))
		return keepassxExtantionAPI::kpxErrorMsg;

	
	QString currentUrl;
	std::string UrlsJSONUtf8 ("[ "); //buffer for JSON array
	
	QList<IEntryHandle*> entriesList = db->entries();
	for(int i=0; i<entriesList.size(); i++){
		if( entriesList[i]->isValid()) {
			currentUrl = entriesList[i]->url();
			UrlsJSONUtf8 += "\"";
			UrlsJSONUtf8 += currentUrl.toUtf8().constData();
			UrlsJSONUtf8 += "\", ";
		}
	}
	UrlsJSONUtf8 += "]";
	
	if(keepassxExtantionAPI::closeDatabase(filename))
		return kpxErrorMsg;
	
	return UrlsJSONUtf8;
}


std::string  keepassxExtantionAPI::getAccount(std::string filename, std::string openPass, std::string url){
	
	keepassxExtantionAPI::init();
	
	SecString secPass;
	QString tmpPass = QString::fromStdString(openPass);
	// owerwrite openPass
	if( openPass.size() )
		for(int i=0; i<openPass.size(); i++)
			openPass[i]=0;
	// set secPass and owerwrite tmpPass
	secPass.setString(tmpPass, true);
	
	
	// Try open database
	dbReadOnly = true;
	if(keepassxExtantionAPI::openDatabase(filename, &secPass))
		return keepassxExtantionAPI::kpxErrorMsg;
	
	
	QString searchURL = QString::fromStdString(url);
	
	QString currentStr;
	SecString currentPass;
	std::string JSONUtf8 ("[ "); //buffer for JSON array of objects
	
	bool Fields[6];
	Fields[0]=false; //Title
	Fields[1]=false; //Username
	Fields[2]=true;  //URL
	Fields[3]=false; //Password
	Fields[4]=false; //Comment
	Fields[5]=false; //Attachment

	//QList<IEntryHandle*> search(IGroupHandle* Group,const QString& SearchString, bool CaseSensitve, bool RegExp,bool Recursive,bool* Fields);
	QList<IEntryHandle*> searchResults = db->search(NULL,searchURL,false,false,true,Fields);

	for(int i=0; i<searchResults.size(); i++){
		if( searchResults[i]->isValid()) {
			JSONUtf8 += "{ \"title\" : \"";
			currentStr = searchResults[i]->title();
			JSONUtf8 += currentStr.toUtf8().constData();
			
			JSONUtf8 += "\", \"username\" : \"";
			currentStr = searchResults[i]->username();
			JSONUtf8 += currentStr.toUtf8().constData();
			
			JSONUtf8 += "\", \"url\" : \"";
			currentStr = searchResults[i]->url();
			JSONUtf8 += currentStr.toUtf8().constData();
			
			JSONUtf8 += "\", \"password\" : \"";
			currentPass = searchResults[i]->password();
			currentPass.unlock();
			currentStr = currentPass.string();
			currentPass.lock();
			JSONUtf8 += currentStr.toUtf8().constData();
			
			JSONUtf8 += "\" }, ";

		}
	}
	
	JSONUtf8 += " ]";
	
	
	if(keepassxExtantionAPI::closeDatabase(filename))
		return kpxErrorMsg;

	return JSONUtf8;
}


