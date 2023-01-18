#ifndef _HAVE_CLI_H
#define _HAVE_CLI_H

#include <request.hpp>

class Cli {
  public:
    void help();
    int interact();
  protected:
    char command[256];
    std::vector <Request> requests;

    void do_list();
    int do_delete();
    void do_clear();
    void do_report();
    void do_exit();
    int parse_command();
    int parse_request();
};

#endif