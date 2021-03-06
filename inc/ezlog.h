/*
 * Eagle Zhang Project
 * ezlog.h
 * Create on 2017-01-08
 * author : Eagle Zhang
 * Copyright (c) 2016 Eagle Zhang
 */

#ifndef __EZLOG_H__
#define __EZLOG_H__

#ifdef __cplusplus
extern "C" {
#endif

#define EZLOG_MODNAME_LEN 3
#define EZLOG_PATH_LEN 64
#define EZLOG_FILE_PREFIX_LEN 32

typedef struct EZLog_t EZLog_t;

typedef enum _EZLogLevel_e {
    EZLOG_ERR = 0,
    EZLOG_WARN,
    EZLOG_INFO,
    EZLOG_DEBUG
} EZLogLevel_t;

typedef struct _EZLog_InitParam_s {
    EZLogLevel_t tLogLevel;
    int iConsleOutPut;
    char aFilePath[EZLOG_PATH_LEN];
    char aFilePrefix[EZLOG_FILE_PREFIX_LEN];
    int iMaxLogFile;
} EZLog_InitParam_t;

int EZLog_Init(EZLog_t **ppEZLog, const EZLog_InitParam_t *pParam);
int EZLog_Uninit(EZLog_t *pEZLog);
int vEZLog(EZLog_t *pEZLog, const char aModName[EZLOG_MODNAME_LEN],
           int iLogLevel, const char *fmt, va_list args);
int EZLog(EZLog_t *pEZLog, const char aModName[EZLOG_MODNAME_LEN],
          int iLogLevel, const char *fmt, ...);

/**
 * Method:    EZLog_SetLogLevel
 *     Set the logging level
 * Returns:   int
 * Qualifier:
 * Parameter: EZLog_t * pEZLog
 * Parameter: int iLogLevel
 */
int EZLog_SetLogLevel(EZLog_t *pEZLog, int iLogLevel);

/**
 * Method:    EZLog_SetConsoleLog
 * Returns:   int
 * Qualifier:
 * Parameter: int iConsole
 *      0:disable console out put, other values to enable console out put
 */
int EZLog_SetConsoleLog(EZLog_t *pEZLog, int iConsole);

#define EZLogErr(pEZLog, aModName, fmt, ...)                                   \
    EZLog(pEZLog, aModName, EZLOG_ERR, fmt, ##__VA_ARGS__)
#define EZLogWarn(pEZLog, aModName, fmt, ...)                                  \
    EZLog(pEZLog, aModName, EZLOG_WARN, fmt, ##__VA_ARGS__)
#define EZLogInfo(pEZLog, aModName, fmt, ...)                                  \
    EZLog(pEZLog, aModName, EZLOG_INFO, fmt, ##__VA_ARGS__)
#define EZLogDebug(pEZLog, aModName, fmt, ...)                                 \
    EZLog(pEZLog, aModName, EZLOG_DEBUG, fmt, ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif
