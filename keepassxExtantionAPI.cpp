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
    registerMethod("echo",      make_method(this, &keepassxExtantionAPI::echo));
    registerMethod("testEvent", make_method(this, &keepassxExtantionAPI::testEvent));
    registerMethod("add",		make_method(this, &keepassxExtantionAPI::add));
	registerMethod("openDatabase",		make_method(this, &keepassxExtantionAPI::openDatabase));

	
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
//bool keepassxExtantionAPI::openDatabase(IDatabase* db, QString filename)
int keepassxExtantionAPI::openDatabase()
{
	//return 1;
	
	//db=NULL;
	db = new Kdb3Database();
	dbReadOnly = false;
	const QString ArgFile="1.kdb";
	
	initYarrow(); //init random number generator
	SecString::generateSessionKey();
	
	
	
	QString pass = "1";
	QString keyfile = "";
	db->setKey(pass, keyfile);

	db->load("/tmp/1.kdb", dbReadOnly);
	
	int t = db->numEntries();
	
	
	return t;
	
	
//	if(!ArgFile.isEmpty()){
//		//QString filename = QDir::cleanPath(QDir::current().absoluteFilePath(ArgFile));
//		QString filename = QDir::cleanPath("/tmp/1.kdb");
//		//openDatabase(db, f);
//		
//		if (QFile::exists(filename)){
//			if(db->load(filename, dbReadOnly)){
//				return 2;
//			}
//			else {
//				return 0;
//			}
//
//		}
//		else {
//			return 0;
//		}
//		
//	}
//	else {
//		return 0;
//	}
	return 2;


	

	//db = new Kdb3Database();
	//Kdb3Database* db = new Kdb3Database();
	//dbReadOnly = false;
	
//	db->setKey(pass, keyfile);
	
	
	
	
	//ICustomIcons* CustomIconsDb=dynamic_cast<ICustomIcons*>(db);
	//IDatabase* db_new=dynamic_cast<IDatabase*>(new Kdb3Database());
	
	//return true;
	return 4;
}
