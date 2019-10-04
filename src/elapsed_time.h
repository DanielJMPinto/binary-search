//
// Tomás Oliveira e Silva, AED, September 2018
//
// code to measure the elapsed time used by a program
//
// use as follows:
//
//   (void)elapsed_time();
//   // put your code to be time measured here
//   dt = elapsed_time();
//

/**
 *  @brief elapsed_time.h is a file used to measure the time of execution of a program.
 *
 */


#if defined(__linux__) || defined(__APPLE__)

//
// GNU/Linux and MacOS code to measure elapsed time
//

#include <time.h>
/**
 *  @brief Elapsed Time.
 */
double elapsed_time(void)
{

  static struct timespec last_time,current_time;

  last_time = current_time;
  if(clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&current_time) != 0)  /*! the first argument could also be CLOCK_REALTIME */
    return -1.0; /*!< If clock_gettime() fails, returns -1 */ 
  return ((double)current_time.tv_sec - (double)last_time.tv_sec) +
         1.0e-9 * ((double)current_time.tv_nsec - (double)last_time.tv_nsec); /*!returns the elapsed time */
}

#endif


#if defined(_MSC_VER) || defined(_WIN32) || defined(_WIN64)

//
// Microsoft Windows code to measure elapsed time
//

#include <windows.h>
/**
 *  @brief Elapsed Time.
 */
double elapsed_time(void)
{
  static LARGE_INTEGER frequency,last_time,current_time;
  static int first_time = 1;

  if(first_time != 0)
  {
    QueryPerformanceFrequency(&frequency);
    first_time = 0;
  }
  last_time = current_time;
  QueryPerformanceCounter(&current_time);
  return (double)(current_time.QuadPart - last_time.QuadPart) / (double)frequency.QuadPart; /*!returns the elapsed time */
}

#endif
