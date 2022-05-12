#ifndef STATEMENT_HPP
#define STATEMENT_HPP

enum ReadTable{
    READ_SUCCESS,
    FAILED_TO_OPEN_FILE_TABLE,
    FILE_TYPE_NOT_MATCH_TABLE,
    COl_NOT_MATCH,
    ENCODING_NOT_MATCH
};
enum WriteTable{
    WRITE_SUCCESS,
    FAILED_TO_OPEN_FILE_WRITE_TABLE
}
enum ReadDatabase{
    READ_DATABASE_SUCCESS,
    FILE_FORMAT_ERROR_DB,
    FAILED_TO_OPEN_FILE_DB,
};
enum WriteDatabase{
    WRITE_DATABASE_SUCCESS,
    FAILED_TO_OPEN_FILE_DB_OUT,
};
typedef enum {
    PREPARE_SUCCESS,
    PREPARE_NEGATIVE_ID,
    PREPARE_STRING_TOO_LONG,
    PREPARE_SYNTAX_ERROR,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;
typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;
typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT,
    STATEMENT_CREATE_DB,
    STATEMENT_CREATE_TABLE,
    STATEMENT_DROP_DB,
    STATEMENT_DROP_TABLE
} StatementType;
typedef enum {
    EXECUTE_SUCCESS,
    EXECUTE_DUPLICATE_KEY,
} ExecuteResult;

#endif