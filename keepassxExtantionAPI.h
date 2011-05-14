/**********************************************************\

  Auto-generated keepassxExtantionAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "keepassxExtantion.h"

// TEST
#include <QtCore>

//#include "Database.h"
#include "Kdb3Database.h"


#ifndef H_keepassxExtantionAPI
#define H_keepassxExtantionAPI

class keepassxExtantionAPI : public FB::JSAPIAuto
{
public:
    keepassxExtantionAPI(const keepassxExtantionPtr& plugin, const FB::BrowserHostPtr& host);
    virtual ~keepassxExtantionAPI();

    keepassxExtantionPtr getPlugin();

    // Read/Write property ${PROPERTY.ident}
    std::string get_testString();
    void set_testString(const std::string& val);

    // Read-only property ${PROPERTY.ident}
    std::string get_version();

    // Method echo
    FB::variant echo(const FB::variant& msg);
    
    // Method test-event
    void testEvent(const FB::variant& s);
	
	// Method add
	long add(long a, long b, long c);
	
	//FB::variant get_param();
	
	// Method openDatabase
//	bool openDatabase(IDatabase* db, QString filename);
	int openDatabase();
	
public:
	IDatabase* db;

private:
    keepassxExtantionWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;

    std::string m_testString;

	bool dbReadOnly;
};

#endif // H_keepassxExtantionAPI

