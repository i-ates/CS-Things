//
// Created by Ates on 11/27/2020.
//

#ifndef ASSIGNMENT2_LIBRARYSYSTEM_H
#define ASSIGNMENT2_LIBRARYSYSTEM_H
#include <string>
#include <fstream>

using namespace  std;

struct movie{
    int id;
    string title;
    int year;
};


struct checked{
    movie *data;
    checked *next;
};

struct user{
    int id;
    string name;
    checked *movie_list;
    user *next;
    user *prev;
};

struct non_checked{
    movie *data;
    non_checked *next;
};


class LibrarySystem {
public:
    ofstream  o_file;
    ifstream  i_file;
    user *user_list;
    non_checked *non_checked_list;

    LibrarySystem(char *input_file ,char *output_file);
    virtual ~LibrarySystem();

    void addMovie(const int movieId, const string movieTitle, const int year);
    void deleteMovie(const int movieId);

    void addUser(const int userId, const string userName);
    void deleteUser(const int userId);

    void checkoutMovie(const int movieId, const int userId);
    void returnMovie(const int movieId);

    void showAllMovies();
    void showMovie(const int movieId);
    void showUser(const int userId);

    void executeCommands();
    void deleteMovie1(const int movieId);

    void addMovie1(const int movieId, const string movieTitle, const int year);
};


#endif //ASSIGNMENT2_LIBRARYSYSTEM_H
