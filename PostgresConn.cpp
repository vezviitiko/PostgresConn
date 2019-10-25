#include "PostgresConn.h"

bool PostgreSQL::OpenDB(String conninfo)
{
    if(!m_session.Open(conninfo))
    {
        LOG("Ошибка при открытии = " << m_session.GetLastError());
        return false;
    }
    
#ifdef _DEBUG
	m_session.SetTrace();
#endif

	SQL = m_session;
	return true;
}

void PostgreSQL::CloseDB()
{
    m_session.Close();
}

String PostgreSQL::ParsePathPostgres_INI(String FileName){
	VectorMap<String, String> cfg = LoadIniFile(FileName);
	String conninfo = "host=" + cfg.Get("IP", Null) + " dbname=" + cfg.Get("DATABASE", Null) + " user=" + cfg.Get("USER", Null) + " password=" + cfg.Get("PASSWORD", Null);
	return conninfo;
}
