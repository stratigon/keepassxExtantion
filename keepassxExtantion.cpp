/**********************************************************\

  Auto-generated keepassxExtantion.cpp

  This file contains the auto-generated main plugin object
  implementation for the keepassx-extantion project

\**********************************************************/

#include "keepassxExtantionAPI.h"

#include "keepassxExtantion.h"


//#include "Kdb3Database.h"
//#include "Database.h"
//db = new Kdb3Database();
//Kdb3Database db;
//Kdb3Database* db = new Kdb3Database();
//ICustomIcons* CustomIconsDb=dynamic_cast<ICustomIcons*>(db);

#include "lib/SecString.h"
SecString Passwd;


//IDatabase* db_new=dynamic_cast<IDatabase*>(new Kdb3Database());
//db_new

///////////////////////////////////////////////////////////////////////////////
/// @fn keepassxExtantion::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginInitialize()
///
/// @see FB::FactoryBase::globalPluginInitialize
///////////////////////////////////////////////////////////////////////////////
void keepassxExtantion::StaticInitialize()
{
    // Place one-time initialization stuff here; As of FireBreath 1.4 this should only
    // be called once per process
}

///////////////////////////////////////////////////////////////////////////////
/// @fn keepassxExtantion::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginDeinitialize()
///
/// @see FB::FactoryBase::globalPluginDeinitialize
///////////////////////////////////////////////////////////////////////////////
void keepassxExtantion::StaticDeinitialize()
{
    // Place one-time deinitialization stuff here. As of FireBreath 1.4 this should
    // always be called just before the plugin library is unloaded
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  keepassxExtantion constructor.  Note that your API is not available
///         at this point, nor the window.  For best results wait to use
///         the JSAPI object until the onPluginReady method is called
///////////////////////////////////////////////////////////////////////////////
keepassxExtantion::keepassxExtantion()
{
	//setParams("data");
	//m_supportedParamSet.insert("data");
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  keepassxExtantion destructor.
///////////////////////////////////////////////////////////////////////////////
keepassxExtantion::~keepassxExtantion()
{
    // This is optional, but if you reset m_api (the shared_ptr to your JSAPI
    // root object) and tell the host to free the retained JSAPI objects then
    // unless you are holding another shared_ptr reference to your JSAPI object
    // they will be released here.
    releaseRootJSAPI();
    m_host->freeRetainedObjects();
}

void keepassxExtantion::onPluginReady()
{
    // When this is called, the BrowserHost is attached, the JSAPI object is
    // created, and we are ready to interact with the page and such.  The
    // PluginWindow may or may not have already fire the AttachedEvent at
    // this point.
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  Creates an instance of the JSAPI object that provides your main
///         Javascript interface.
///
/// Note that m_host is your BrowserHost and shared_ptr returns a
/// FB::PluginCorePtr, which can be used to provide a
/// boost::weak_ptr<keepassxExtantion> for your JSAPI class.
///
/// Be very careful where you hold a shared_ptr to your plugin class from,
/// as it could prevent your plugin class from getting destroyed properly.
///////////////////////////////////////////////////////////////////////////////
FB::JSAPIPtr keepassxExtantion::createJSAPI()
{
    // m_host is the BrowserHost
    return boost::make_shared<keepassxExtantionAPI>(FB::ptr_cast<keepassxExtantion>(shared_from_this()), m_host);
}

bool keepassxExtantion::onMouseDown(FB::MouseDownEvent *evt, FB::PluginWindow *)
{
    //printf("Mouse down at: %d, %d\n", evt->m_x, evt->m_y);
    return false;
}

bool keepassxExtantion::onMouseUp(FB::MouseUpEvent *evt, FB::PluginWindow *)
{
    //printf("Mouse up at: %d, %d\n", evt->m_x, evt->m_y);
    return false;
}

bool keepassxExtantion::onMouseMove(FB::MouseMoveEvent *evt, FB::PluginWindow *)
{
    //printf("Mouse move at: %d, %d\n", evt->m_x, evt->m_y);
    return false;
}
bool keepassxExtantion::onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindow *)
{
    // The window is attached; act appropriately
    return false;
}

bool keepassxExtantion::onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindow *)
{
    // The window is about to be detached; act appropriately
    return false;
}

