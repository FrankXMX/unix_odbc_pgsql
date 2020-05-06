#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include <stdio.h>


#define OTL_ODBC // CompileOTL 4.0/ODBC  
#define OTL_ODBC_UNIX // uncomment this line if UnixODBC is used
//#define OTL_UNICODE // Compile OTL with Unicode    --->屏蔽 使用时中文显示乱码

#include "otlv4.h" // include the OTL 4.0 header file

otl_connect db; // connect object

void select()
{ 
    try{
        otl_stream ostream1(500, // buffer size
            "select * from otluser.company;",// SELECT statement
            db // connect object
            ); 
        // create select stream

        int id;
        int age;
        unsigned char name[255];
        unsigned char address[255];
        double salary;

        while(!ostream1.eof())
        { // while not end-of-data
            //ostream1>>id>>user>>name;
            ostream1>>id;
            ostream1>>name;
            ostream1>>age;
            ostream1>>address;
            ostream1>>salary;
            cout<<"id="<<id<<endl;
            cout<<"age="<<age<<endl;
            cout<<"name="<<name<<endl;
        }
    }
    catch(otl_exception& p)
    { // intercept OTL exceptions
        cout<<"otl_exception:"<<endl;
        cerr<<p.msg<<endl; // print out error message
        cerr<<p.stm_text<<endl; // print out SQL that caused the error
        cerr<<p.var_info<<endl; // print out the variable that caused the error
    }
}

int main()
{
    otl_connect::otl_initialize(); // initialize the database API environment
    try{
        db.rlogon("DSN=pgsql;UID=postgres;PWD=postgres;database=otlodbc"); // connect to the database
        select(); // select records from table
    }

    catch(otl_exception& p){ // intercept OTL exceptions
        cerr<<p.msg<<endl; // print out error message
        cerr<<p.stm_text<<endl; // print out SQL that caused the error
        cerr<<p.var_info<<endl; // print out the variable that caused the error
    }

    db.logoff(); // disconnect from the database

    return 0;

}