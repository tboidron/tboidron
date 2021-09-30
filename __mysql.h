#include <vector>
#include <string>
#include <mysql/mysql.h>

class __mysql
{
	public:
		__mysql();
		~__mysql();
	public:
		unsigned int __query(const char*);		
	public:
		MYSQL*__h__mysql;
	public:	
		//static MYSQL*__connect();
	public:
		static wchar_t**__query(MYSQL*,const char*);
	public:
        MYSQL_RES*__h__res;    		
};

class CMySqlQuery
{
//    private:
//        unsigned int m_iNbRow,m_iNumFields;
    public:
        std::vector<std::string> m_sz2_result;
    public:
        CMySqlQuery(const char*);
//    public:
//        unsigned int GetNbRow() { return m_iNbRow;}
};

//typedef struct MYSQL_RES {
//   uint64_t row_count;
//   MYSQL_FIELD *fields;
//   struct MYSQL_DATA *data;
//   MYSQL_ROWS *data_cursor;
//   unsigned long *lengths; /* column lengths of current row */
//   MYSQL *handle;          /* for unbuffered reads */
//   const struct MYSQL_METHODS *methods;
//   MYSQL_ROW row;         /* If unbuffered read */
//   MYSQL_ROW current_row; /* buffer to current row */
//   struct MEM_ROOT *field_alloc;
//   unsigned int field_count, current_field;
//   bool eof; /* Used by mysql_fetch_row */
//   /* mysql_stmt_close() had to cancel this result */
//   bool unbuffered_fetch_cancelled;
//   enum enum_resultset_metadata metadata;
//   void *extension;
// } MYSQL_RES;
//  

//typedef char** MYSQL_ROW

// typedef struct MYSQL_ROWS {
//   struct MYSQL_ROWS *next; /* list of rows */
//   MYSQL_ROW data;
//   unsigned long length;
// } MYSQL_ROWS;

