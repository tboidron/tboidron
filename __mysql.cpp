#include "__mysql.h"
#include <cstring>
#include <iomanip>
#include <iostream>



/*Binary    Hex          Comments
0xxxxxxx  0x00..0x7F   Only byte of a 1-byte character encoding
10xxxxxx  0x80..0xBF   Continuation byte: one of 1-3 bytes following the first
110xxxxx  0xC0..0xDF   First byte of a 2-byte character encoding
1110xxxx  0xE0..0xEF   First byte of a 3-byte character encoding
11110xxx  0xF0..0xF7   First byte of a 4-byte character encoding*/


const wchar_t* QUERY_CHARSET=L"SELECT * FROM INFORMATION_SCHEMA.SCHEMATA WHERE SCHEMA_NAME = 'nom_base'";
const wchar_t* QUERY_SIZE=L"SELECT table_schema AS NomBaseDeDonnees,ROUND(SUM( data_length + index_length ) / 1024 / 1024, 2) AS BaseDonneesMo FROM information_schema.TABLES GROUP BY TABLE_SCHEMA;";


const char*SZ_HOST="localhost";
const char*SZ_DATABASE="biosphere";
const char*SZ_PWD="qcxw2zk";

__mysql::__mysql()
{
	__h__mysql=NULL;
	__h__mysql=mysql_init(NULL);
	__h__mysql=mysql_real_connect(__h__mysql,SZ_HOST,NULL,SZ_PWD,SZ_DATABASE,0,NULL,0);   	
	if(__h__mysql==NULL)
		std::cout<<"*************** >> Problème connexion au serveur mysql\n";

}
__mysql::~__mysql()
{
	if(__h__res!=NULL)
		mysql_free_result(__h__res);
}
unsigned int __mysql::__query(const char*sz_req)
{
	__h__res=NULL;
	if(__h__mysql!=NULL)
	{
    	unsigned int _i_err = mysql_query(__h__mysql,sz_req);
		switch(_i_err)
		{
			case CR_COMMANDS_OUT_OF_SYNC:
			case CR_SERVER_GONE_ERROR:			
			case CR_SERVER_LOST:			
			case CR_UNKNOWN_ERROR:			
				std::cout<<"$mysql_query eror number: "<<_i_err<<"\n";			
			    return _i_err;			    
		}    	
        __h__res=mysql_store_result(__h__mysql);        	
        
	    if(mysql_field_count(__h__mysql))
	    {
		    std::cout<<"La requete SQL returne un tableau de: "<<__h__res->field_count<<" colonne(s) x "<<__h__res->row_count<<" ligne(s)\n";   
		    
            MYSQL_ROW row = mysql_fetch_row(__h__res);		         	    
	    }        
    }
    return 0;
}
//MYSQL*__mysql::__connect()
//{
//	static MYSQL*_h_mysql=NULL;
//	
//	MYSQL_RES*_h_res=NULL;
//	
//	if(_h_mysql==NULL)
//	{		
//		const char*sz_host="localhost",*sz_dbname="biosphere",*sz_pwd="qcxw2zk";		
//
//		_h_mysql=mysql_init(NULL);
//		_h_mysql=mysql_real_connect(_h_mysql,sz_host,NULL,sz_pwd,sz_dbname,0,NULL,0);   
//		
//		if(_h_mysql==NULL)
//			std::cout<<"$Problème connexion au serveur mysql\n";
//	}				  
//	return _h_mysql;				  	
//}
wchar_t**__mysql::__query(MYSQL*h_mysql,const char*sz_req)
{
    static wchar_t**_sz2;
    
    //efffacer le tableau de tableau de char precedent
    

    unsigned int _i_err = mysql_query(h_mysql,sz_req);
      
    if(!_i_err)
    {
        MYSQL_RES*_h_res=mysql_store_result(h_mysql);    
    
        unsigned int _i_row=0;
        while(_i_row)
        {
            MYSQL_ROW row = mysql_fetch_row(_h_res);
            _i_row--;
			//std::string sz_00=row[iCurField];
			//m_sz2_result.push_back(row[iCurField]);
        
        }	    
    
    	return _sz2;
    }
    else    
		switch(_i_err)
		{
			case CR_COMMANDS_OUT_OF_SYNC:
			    std::cout << "CR_COMMANDS_OUT_OF_SYNC";			
				break;
			case CR_SERVER_GONE_ERROR:
			    std::cout << "CR_SERVER_GONE_ERROR";						
				break;
			case CR_SERVER_LOST:
			    std::cout << "CR_SERVER_LOST";						
				break;
			case CR_UNKNOWN_ERROR:
			    std::cout << "CR_UNKNOWN_ERROR";						
		}					
	return NULL;
}
/*
*/
CMySqlQuery::CMySqlQuery(const char*sz_request)
{
	MYSQL* h_mysql=NULL;

    unsigned int iErr_00 = mysql_query(h_mysql,sz_request);
    if(!iErr_00)
    {
        m_sz2_result.clear();

        MYSQL_RES * hMySqlRes = mysql_store_result(h_mysql);

        int m_iNbRow = mysql_num_rows(hMySqlRes);
        int m_iNumFields = mysql_num_fields (hMySqlRes);

        std::cout << " : réussie: " << m_iNbRow << " lignes x  " << m_iNumFields  << " colonnes.\n";

        unsigned int iRow = 0;

        while(true)
        {
            MYSQL_ROW row = mysql_fetch_row(hMySqlRes);

            if(row==NULL)
                break;

            for(unsigned int iCurField = 0; iCurField < m_iNumFields ; iCurField++)
            {
                std::cout << std::setw(10) << "[" << iRow << "][" << iCurField << "] = ";

                if(row[iCurField]==NULL)
                {
                    std::cout << "(NULL)";
                    m_sz2_result.push_back("");
                }
                else 
                {
                    unsigned iLen_00 = std::strlen(row[iCurField]);            
                    if(!iLen_00)
                    {
                        std::cout << "{O}";
                        m_sz2_result.push_back("");
                    }
                    else
                    {
                        std::string sz_00=row[iCurField];
                        m_sz2_result.push_back(row[iCurField]);
                        std::cout << std::setw(25) << m_sz2_result[ (m_iNumFields) * iRow + iCurField];
                        //std::cout << row[iCurField] << ",   ";
                        //printf (" %20s,  ",row[iCurField]);
                    }
                }
            }
            iRow++;
            std::cout << "\n";
        }
        
    }
}   


