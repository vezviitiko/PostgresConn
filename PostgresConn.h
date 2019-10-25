#ifndef _PostgresConn_PostgresConn_h_
#define _PostgresConn_PostgresConn_h_

#include <Core/Core.h>

using namespace Upp;

#include <PostgreSQL/PostgreSQL.h>

class PostgreSQL{
public:
    typedef PostgreSQL CLASSNAME;
    bool OpenDB(String conninfo);
    void CloseDB();
    String ParsePathPostgres_INI(String FileName);
protected:
    PostgreSQLSession m_session;
};
#endif
