//
// Created by Ates on 11/27/2020.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "LibrarySystem.h"
#include <sstream>
#include <string>
#include <vector>

using namespace  std;


LibrarySystem::LibrarySystem(char* input_file, char* output_file){
    non_checked_list=new non_checked;
    non_checked_list= nullptr;

    user_list=new user;
    user_list= nullptr;

    o_file.open(output_file,std::ios::out);
    i_file.open(input_file,std::ios::in);

}
LibrarySystem::~LibrarySystem() = default;


void LibrarySystem::addMovie(const int movieId, const string movieTitle, const int year) {
    bool ismovie_find= false; //find=true else false
    if (non_checked_list!= nullptr){
        // search non_checked_list
        non_checked *control= non_checked_list;
        if (non_checked_list->data->id==movieId){
            ismovie_find=true;
        }else{
            if (non_checked_list->data->id==movieId){
                ismovie_find= true;
            }
            non_checked_list=non_checked_list->next;
            while (non_checked_list!=control){
                if (non_checked_list->data->id==movieId){
                    ismovie_find= true;
                    break;
                }else{
                    non_checked_list=non_checked_list->next;
                }
            }
        }

    }


    //search in users
    user *control1= user_list;
    checked *control2;
    //1.user 1. film

    if (user_list!=nullptr){
        if (user_list->movie_list!= nullptr){
            if (user_list->movie_list->data->id==movieId){
                ismovie_find=true;

            }else{
                //1.user diğer filmler
                control2= user_list->movie_list;
                user_list->movie_list=user_list->movie_list->next;
                while (user_list->movie_list!=control2){
                    if (user_list->movie_list->data->id==movieId){
                        ismovie_find= true;
                        break;
                    }else{
                        user_list->movie_list=user_list->movie_list->next;

                    }
                }

            }
        }

        if (!ismovie_find){
            //diğer userlar
            user_list=user_list->next;
            while (user_list!=control1){
                //birinci filmler
                if (user_list->movie_list!= nullptr){
                    if (user_list->movie_list->data->id==movieId){
                        ismovie_find=true;
                        break;
                    }else{
                        //diğer filmler
                        control2= user_list->movie_list;
                        user_list->movie_list=user_list->movie_list->next;
                        while (user_list->movie_list!=control2){
                            if (user_list->movie_list->data->id==movieId){
                                ismovie_find= true;
                                break;
                            }else{
                                user_list->movie_list=user_list->movie_list->next;
                            }
                        }
                    }

                }

                user_list=user_list->next;
            }
        }
    }
    if(!ismovie_find){
        non_checked *new_node=new non_checked;
        new_node->data=new movie;
        new_node->data->id=movieId;
        new_node->data->year=year;
        new_node->data->title=movieTitle;

        if (non_checked_list==nullptr){
            new_node->next=new_node;
            non_checked_list=new_node;
        }else{
            new_node->next=non_checked_list->next;
            non_checked_list->next=new_node;
            non_checked_list=new_node;
        }
        o_file<<"Movie "<<movieId<<" has been added"<<endl;

    }else{
        o_file<<"Movie "<<movieId<<" already exists"<<endl;
    }



}
void LibrarySystem::addMovie1(const int movieId, const string movieTitle, const int year) {
    bool ismovie_find= false; //find=true else false
    if (non_checked_list!= nullptr){
        // search non_checked_list
        non_checked *control= non_checked_list;
        if (non_checked_list->data->id==movieId){
            ismovie_find=true;
        }else{
            if (non_checked_list->data->id==movieId){
                ismovie_find= true;
            }
            non_checked_list=non_checked_list->next;
            while (non_checked_list!=control){
                if (non_checked_list->data->id==movieId){
                    ismovie_find= true;
                    break;
                }else{
                    non_checked_list=non_checked_list->next;
                }
            }
        }

    }


    //search in users
    user *control1= user_list;
    checked *control2;
    //1.user 1. film

    if (user_list!=nullptr){
        if (user_list->movie_list!= nullptr){
            if (user_list->movie_list->data->id==movieId){
                ismovie_find=true;

            }else{
                //1.user diğer filmler
                control2= user_list->movie_list;
                user_list->movie_list=user_list->movie_list->next;
                while (user_list->movie_list!=control2){
                    if (user_list->movie_list->data->id==movieId){
                        ismovie_find= true;
                        break;
                    }else{
                        user_list->movie_list=user_list->movie_list->next;

                    }
                }

            }
        }

        if (!ismovie_find){
            //diğer userlar
            user_list=user_list->next;
            while (user_list!=control1){
                //birinci filmler
                if (user_list->movie_list!= nullptr){
                    if (user_list->movie_list->data->id==movieId){
                        ismovie_find=true;
                        break;
                    }else{
                        //diğer filmler
                        control2= user_list->movie_list;
                        user_list->movie_list=user_list->movie_list->next;
                        while (user_list->movie_list!=control2){
                            if (user_list->movie_list->data->id==movieId){
                                ismovie_find= true;
                                break;
                            }else{
                                user_list->movie_list=user_list->movie_list->next;
                            }
                        }
                    }

                }

                user_list=user_list->next;
            }
        }
    }
    if(!ismovie_find){
        non_checked *new_node=new non_checked;
        new_node->data=new movie;
        new_node->data->id=movieId;
        new_node->data->year=year;
        new_node->data->title=movieTitle;

        if (non_checked_list==nullptr){
            new_node->next=new_node;
            non_checked_list=new_node;
        }else{
            new_node->next=non_checked_list->next;
            non_checked_list->next=new_node;
            non_checked_list=new_node;
        }

    }else{
    }



}

void LibrarySystem::deleteMovie(const int movieId) {

    bool ismovie_find= false; //find=true else false
    bool which_list=false;    //non_checked = true ,   checked=false
    if (non_checked_list!= nullptr){
        // search non_checked_list
        non_checked *control= non_checked_list;
        if (non_checked_list->data->id==movieId){
            ismovie_find=true;
            which_list=true;
        }else{
            if (non_checked_list->data->id==movieId){
                ismovie_find= true;
                which_list=true;
            }
            non_checked_list=non_checked_list->next;
            while (non_checked_list!=control){
                if (non_checked_list->data->id==movieId){
                    ismovie_find= true;
                    which_list=true;
                    break;
                }else{
                    non_checked_list=non_checked_list->next;
                }
            }
        }

    }


    //search in users
    user *control1= user_list;
    checked *control2;
    //1.user 1. film

    if (user_list!=nullptr && !which_list){
        if (user_list->movie_list!= nullptr){
            if (user_list->movie_list->data->id==movieId){
                ismovie_find=true;

            }else{
                //1.user diğer filmler
                control2= user_list->movie_list;
                user_list->movie_list=user_list->movie_list->next;
                while (user_list->movie_list!=control2){
                    if (user_list->movie_list->data->id==movieId){
                        ismovie_find= true;
                        break;
                    }else{
                        user_list->movie_list=user_list->movie_list->next;

                    }
                }

            }
        }

        if (!ismovie_find){
            //diğer userlar
            user_list=user_list->next;
            while (user_list!=control1){
                //birinci filmler
                if (user_list->movie_list!= nullptr){
                    if (user_list->movie_list->data->id==movieId){
                        ismovie_find=true;
                        break;
                    }else{
                        //diğer filmler
                        control2= user_list->movie_list;
                        user_list->movie_list=user_list->movie_list->next;
                        while (user_list->movie_list!=control2){
                            if (user_list->movie_list->data->id==movieId){
                                ismovie_find= true;
                                break;
                            }else{
                                user_list->movie_list=user_list->movie_list->next;
                            }
                        }
                    }

                }

                user_list=user_list->next;
            }
        }
    }
    if (ismovie_find){

        if (which_list){
            //nonchecked
            if (non_checked_list->next==non_checked_list){
                o_file<<"Movie "<<movieId<<" has not been checked out"<<endl;
                o_file<<"Movie "<<movieId<<" has been deleted"<<endl;
                non_checked_list= nullptr;
            }else{
                non_checked *before_node=non_checked_list;
                non_checked *after_node=non_checked_list->next;
                while (non_checked_list->next!=before_node){
                    non_checked_list=non_checked_list->next;
                }

                non_checked_list->next=after_node;
                o_file<<"Movie "<<movieId<<" has not been checked out"<<endl;
                o_file<<"Movie "<<movieId<<" has been deleted"<<endl;
            }
        } else{
            //checked
            if (user_list->movie_list->next==user_list->movie_list){
                user_list->movie_list= nullptr;
            }else{
                checked *before_node=user_list->movie_list;
                checked *after_node=user_list->movie_list->next;
                while (user_list->movie_list->next!=before_node){
                    user_list->movie_list=user_list->movie_list->next;
                }

                user_list->movie_list->next=after_node;
            }
            o_file<<"Movie "<<movieId<<" has been checked out"<<endl;
            o_file<<"Movie "<<movieId<<" has been deleted"<<endl;
        }
    }else{
        o_file<<"Movie "<<movieId<<" does not exist"<<endl;
    }
}
void LibrarySystem::deleteMovie1(const int movieId) {
    bool ismovie_find= false; //find=true else false
    bool which_list=false;    //non_checked = true ,   checked=false
    if (non_checked_list!= nullptr){
        // search non_checked_list
        non_checked *control= non_checked_list;
        if (non_checked_list->data->id==movieId){
            ismovie_find=true;
            which_list=true;
        }else{
            if (non_checked_list->data->id==movieId){
                ismovie_find= true;
                which_list=true;
            }
            non_checked_list=non_checked_list->next;
            while (non_checked_list!=control){
                if (non_checked_list->data->id==movieId){
                    ismovie_find= true;
                    which_list=true;
                    break;
                }else{
                    non_checked_list=non_checked_list->next;
                }
            }
        }

    }


    //search in users
    user *control1= user_list;
    checked *control2;
    //1.user 1. film

    if (user_list!=nullptr && !which_list){
        if (user_list->movie_list!= nullptr){
            if (user_list->movie_list->data->id==movieId){
                ismovie_find=true;

            }else{
                //1.user diğer filmler
                control2= user_list->movie_list;
                user_list->movie_list=user_list->movie_list->next;
                while (user_list->movie_list!=control2){
                    if (user_list->movie_list->data->id==movieId){
                        ismovie_find= true;
                        break;
                    }else{
                        user_list->movie_list=user_list->movie_list->next;

                    }
                }

            }
        }

        if (!ismovie_find){
            //diğer userlar
            user_list=user_list->next;
            while (user_list!=control1){
                //birinci filmler
                if (user_list->movie_list!= nullptr){
                    if (user_list->movie_list->data->id==movieId){
                        ismovie_find=true;
                        break;
                    }else{
                        //diğer filmler
                        control2= user_list->movie_list;
                        user_list->movie_list=user_list->movie_list->next;
                        while (user_list->movie_list!=control2){
                            if (user_list->movie_list->data->id==movieId){
                                ismovie_find= true;
                                break;
                            }else{
                                user_list->movie_list=user_list->movie_list->next;
                            }
                        }
                    }

                }

                user_list=user_list->next;
            }
        }
    }
    if (ismovie_find){

        if (which_list){
            //nonchecked
            if (non_checked_list->next==non_checked_list){
                non_checked_list= nullptr;
//                non_checked_list->next= nullptr;
            }else{
                non_checked *before_node=non_checked_list;
                non_checked *after_node=non_checked_list->next;
                while (non_checked_list->next!=before_node){
                    non_checked_list=non_checked_list->next;
                }

                non_checked_list->next=after_node;

            }
        } else{
            //checked

            if (user_list->movie_list->next==user_list->movie_list){
                user_list->movie_list= nullptr;
            }else{
                checked *before_node=user_list->movie_list;
                checked *after_node=user_list->movie_list->next;
                while (user_list->movie_list->next!=before_node){
                    user_list->movie_list=user_list->movie_list->next;
                }

                user_list->movie_list->next=after_node;
            }

        }
    }else{
    }
}

void LibrarySystem::addUser(const int userId, const string userName) {
    user *temp=new user;
    temp->id=userId;
    temp->name=userName;

    bool check=false;
    if (user_list== nullptr){
        temp->next=temp->prev=temp;
        temp->movie_list= nullptr;
        user_list=temp;
        o_file<<"User "<<userId<<" has been added"<<endl;
    }else{
        user *control=user_list;
        //liste tek elemanlıysa diye
        if (user_list->id==userId){
            check=true;
        }
        user_list=user_list->next;
        while (control!=user_list){
            if (user_list->id==userId){
                check= true;
                break;
            }
            user_list=user_list->next;

        }
        if (!check){
            user *last_node=user_list->prev;
            temp->next=user_list;
            user_list->prev=temp;
            temp->prev=last_node;
            temp->movie_list= nullptr;
            last_node->next=temp;
            o_file<<"User "<<userId<<" has been added"<<endl;

        }else{
            o_file<<"User "<<userId<<" already exists"<<endl;
        }

    }
}

void LibrarySystem::deleteUser(const int userId) {
    if (user_list== nullptr){
        o_file<<"User "<<userId<<" does not exist"<<endl;

    }else{
        user *control=user_list;
        user *prev=nullptr;
        while (user_list->id!=userId){
            if (user_list->next==control){
                o_file<<"User "<<userId<<" does not exist"<<endl;
                return;
            }
            prev=user_list;
            user_list=user_list->next;
        }
        if (user_list->next==user_list && prev== nullptr){
            o_file<<"User "<<userId<<" has been deleted"<<endl;
            user_list= nullptr;
            return;
        }
        if (user_list==control){
            o_file<<"User "<<userId<<" has been deleted"<<endl;
            prev=control->prev;
            control=control->next;
            prev->next=control;
            control->prev=prev;
            control->movie_list= nullptr;
            user_list=control;
        }else if(user_list->next==control){
            o_file<<"User "<<userId<<" has been deleted"<<endl;

            prev->next=control;
            control->prev=prev;
            control->movie_list= nullptr;
            user_list=control;
        }else{
            o_file<<"User "<<userId<<" has been deleted"<<endl;
            user *temp= user_list->next;
            prev->next=temp;
            temp->prev=prev;
            temp->movie_list= nullptr;
            user_list=temp;
        }
    }

}

void LibrarySystem::checkoutMovie(const int movieId, const int userId) {
    if (user_list== nullptr){
        o_file<<"User "<<userId<<" does not exist for checkout"<<endl;
        return;
    }
    if (non_checked_list== nullptr){
        o_file<<"Movie "<<movieId<<" does not exist for checkout"<<endl;
        return;
    }
    user *control=user_list;
    while (user_list->id!=userId){
        if (user_list->next==control){
            o_file<<"User "<<userId<<" does not exist for checkout"<<endl;
            return;
        }
        user_list=user_list->next;
    }

    bool ismovie_find= false; //find=true else false
    // search non_checked_list
    non_checked *control1= non_checked_list;
    if (non_checked_list->data->id==movieId){
        ismovie_find=true;
    }else{
        non_checked_list=non_checked_list->next;
        while (non_checked_list!=control1){
            if (non_checked_list->data->id==movieId){
                ismovie_find= true;
                break;
            }else{
                non_checked_list=non_checked_list->next;
            }
        }
    }
    if (!ismovie_find){
        o_file<<"Movie "<<movieId<<" does not exist for checkout"<<endl;
        return;
    }
    checked *temp=new checked;
    temp->data=new movie;
    temp->data->id=non_checked_list->data->id;
    temp->data->title=non_checked_list->data->title;
    temp->data->year=non_checked_list->data->year;

    if (user_list->movie_list== nullptr){
        temp->next=temp;
        user_list->movie_list=temp;
        deleteMovie1(user_list->movie_list->data->id);
    }else{
        temp->next=user_list->movie_list->next;
        user_list->movie_list->next=temp;
        user_list->movie_list=temp;
        deleteMovie1(temp->data->id);
    }
    o_file<<"Movie "<<movieId<<" has been checked out by User "<<userId<<endl;


}

void LibrarySystem::returnMovie(const int movieId) {
    bool ismovie_find= false; //find=true else false
    bool which_list=false;    //non_checked = true ,   checked=false
    if (non_checked_list!= nullptr ){
        // search non_checked_list
        non_checked *control= non_checked_list;
        if (non_checked_list->data->id==movieId){
            ismovie_find=true;
            which_list=true;
        }else{
            if (non_checked_list->data->id==movieId){
                ismovie_find= true;
                which_list=true;
            }
            non_checked_list=non_checked_list->next;
            while (non_checked_list!=control){
                if (non_checked_list->data->id==movieId){
                    ismovie_find= true;
                    which_list=true;
                    break;
                }else{
                    non_checked_list=non_checked_list->next;
                }
            }
        }
    }


    //search in users
    user *control1= user_list;
    checked *control2;
    //1.user 1. film
    if (user_list!=nullptr && !which_list ){
        if (user_list->movie_list!= nullptr){
            if (user_list->movie_list->data->id==movieId){
                ismovie_find=true;

            }else{
                //1.user diğer filmler
                control2= user_list->movie_list;
                user_list->movie_list=user_list->movie_list->next;
                while (user_list->movie_list!=control2){
                    if (user_list->movie_list->data->id==movieId){
                        ismovie_find= true;
                        break;
                    }else{
                        user_list->movie_list=user_list->movie_list->next;

                    }
                }
            }

        }

        if (!ismovie_find){
            //diğer userlar
            user_list=user_list->next;

            while (user_list!=control1 && !ismovie_find){
                //birinci filmler
                if (user_list->movie_list!= nullptr){
                    if (user_list->movie_list->data->id==movieId){
                        ismovie_find=true;
                        break;
                    }else{
                        //diğer filmler
                        control2= user_list->movie_list;
                        user_list->movie_list=user_list->movie_list->next;
                        while (user_list->movie_list!=control2){
                            if (user_list->movie_list->data->id==movieId){
                                ismovie_find= true;
                                break;
                            }else{
                                user_list->movie_list=user_list->movie_list->next;
                            }
                        }
                    }
                }
                user_list=user_list->next;

            }
        }
    }
    if (ismovie_find){

        if (which_list){
            //nonchecked
            o_file<<"Movie "<<non_checked_list->data->id<<" has not been checked out"<<endl;
        } else{
            //checked
            o_file<<"Movie "<<user_list->prev->movie_list->data->id<<" has been returned"<<endl;
            int id=user_list->prev->movie_list->data->id;
            string title=user_list->prev->movie_list->data->title;
            int year= user_list->prev->movie_list->data->year;
            deleteMovie1(user_list->prev->movie_list->data->id);
            addMovie1(id,title,year);
        }
    }else{
        o_file<<"Movie "<<movieId<<" not exist in the library"<<endl;
    }

}

void LibrarySystem::showAllMovies() {
    o_file<<"Movie id - Movie name - Year - Status"<<endl;
    if (non_checked_list!= nullptr){
        non_checked *control= non_checked_list;
        o_file<<non_checked_list->data->id<<" "<<non_checked_list->data->title<<" "
        <<non_checked_list->data->year<<" Not checked out"<<endl;
        non_checked_list=non_checked_list->next;
        while (non_checked_list!=control){
            o_file<<non_checked_list->data->id<<" "<<non_checked_list->data->title<<" "
                <<non_checked_list->data->year<<" Not checked out"<<endl;
            non_checked_list=non_checked_list->next;
        }
    }else{

    }

    if (user_list!=nullptr){

        user *control1=user_list;
        checked *control2= user_list->movie_list;
       if (user_list->movie_list!= nullptr){
           //1.user 1.ci film
           o_file<<user_list->movie_list->data->id<<" "<<user_list->movie_list->data->title<<" "
               <<user_list->movie_list->data->year<<" Checked out by User "<<user_list->id<<endl;
           if (user_list->movie_list->next!=user_list->movie_list){
               user_list->movie_list=user_list->movie_list->next;
              //1.user diğer filmler
               while (user_list->movie_list!=control2){
                   o_file<<user_list->movie_list->data->id<<" "<<user_list->movie_list->data->title<<" "
                       <<user_list->movie_list->data->year<<" Checked out by User "<<user_list->id<<endl;
                   user_list->movie_list=user_list->movie_list->next;
               }
               //diğer userlar

           }
        }
        user_list=user_list->next;
        while (control1!=user_list){
            //diğer userlar 1.film
            if (user_list->movie_list!= nullptr){
                o_file<<user_list->movie_list->data->id<<" "<<user_list->movie_list->data->title<<" "
                    <<user_list->movie_list->data->year<<" Checked out by User "<<user_list->id<<endl;
                control2=user_list->movie_list;

                if (user_list->movie_list->next!=user_list->movie_list){
                    user_list->movie_list=user_list->movie_list->next;
                    //diğer userlar diğer filmler
                    while (user_list->movie_list!=control2){
                        o_file<<user_list->movie_list->data->id<<" "<<user_list->movie_list->data->title<<" "
                            <<user_list->movie_list->data->year<<" Checked out by User "<<user_list->id<<endl;
                        user_list->movie_list=user_list->movie_list->next;
                    }
                }
            }
            user_list=user_list->next;
        }
    }

}

void LibrarySystem::showMovie(const int movieId) {
    bool ismovie_find= false; //find=true else false
    bool which_list=false;    //non_checked = true ,   checked=false

    if (non_checked_list!= nullptr){
        // search non_checked_list
        non_checked *control= non_checked_list;
        if (non_checked_list->data->id==movieId){
            ismovie_find=true;
            which_list=true;
        }else{
            if (non_checked_list->data->id==movieId){
                ismovie_find= true;
                which_list=true;
            }
            non_checked_list=non_checked_list->next;
            while (non_checked_list!=control){
                if (non_checked_list->data->id==movieId){
                    ismovie_find= true;
                    which_list=true;
                    break;
                }else{
                    non_checked_list=non_checked_list->next;
                }
            }
        }
    }


    ///search in users
    user *control1= user_list;
    checked *control2;
    //1.user 1. film

    if (user_list!=nullptr && !which_list){
        if (user_list->movie_list!= nullptr){
            if (user_list->movie_list->data->id==movieId){
                ismovie_find=true;

            }else{
                //1.user diğer filmler
                control2= user_list->movie_list;
                user_list->movie_list=user_list->movie_list->next;
                while (user_list->movie_list!=control2){
                    if (user_list->movie_list->data->id==movieId){
                        ismovie_find= true;
                        break;
                    }else{
                        user_list->movie_list=user_list->movie_list->next;

                    }
                }

            }
        }

        if (!ismovie_find){
            //diğer userlar
            user_list=user_list->next;
            while (user_list!=control1){
                //birinci filmler
                if (user_list->movie_list!= nullptr){
                    if (user_list->movie_list->data->id==movieId){
                        ismovie_find=true;
                        break;
                    }else{
                        //diğer filmler
                        control2= user_list->movie_list;
                        user_list->movie_list=user_list->movie_list->next;
                        while (user_list->movie_list!=control2){
                            if (user_list->movie_list->data->id==movieId){
                                ismovie_find= true;
                                break;
                            }else{
                                user_list->movie_list=user_list->movie_list->next;
                            }
                        }
                    }

                }

                user_list=user_list->next;
            }
        }
    }
    if (ismovie_find ){

        if (which_list){
            //nonchecked
            o_file<<movieId<<" "<<non_checked_list->data->title<<" "<<non_checked_list->data->year<<
            " Not checked out"<<endl;

        } else{
            //checked
            o_file<<movieId<<" "<<user_list->movie_list->data->title<<" "<<user_list->movie_list->data->year<<
                " Checked out by User "<<user_list->id<<endl;
        }
    }else{
        o_file<<"Movie with the id "<<movieId<<" does not exist"<<endl;
    }

}

void LibrarySystem::showUser(const int userId) {
    if (user_list== nullptr){
        o_file<<"User "<<userId<<" does not exist"<<endl;
    }else {
        user *control = user_list;
        while (user_list->id != userId) {
            if (user_list->next == control) {
                o_file<<"User "<<userId<<" does not exist"<<endl;
                return;
            }
            user_list = user_list->next;
        }
        o_file<<"User id: "<<userId<<" User name: "<<user_list->name<<endl;
        o_file<<"User "<<userId<<" checked out the following Movies:"<<endl;
        if (user_list->movie_list!= nullptr){
            o_file<<"Movie id - Movie name - Year"<<endl;
            checked *control1=user_list->movie_list;
            o_file<<user_list->movie_list->data->id<<" "<<user_list->movie_list->data->title<<" "<<
                user_list->movie_list->data->year<<endl;
            user_list->movie_list=user_list->movie_list->next;
            while (user_list->movie_list!=control1){
                o_file<<user_list->movie_list->data->id<<" "<<user_list->movie_list->data->title<<" "<<
                    user_list->movie_list->data->year<<endl;
                user_list->movie_list=user_list->movie_list->next;
            }
        }

    }
}

void LibrarySystem::executeCommands() {
    o_file<<"===Movie Library System==="<<endl<<endl;
    string line;
    int count=0;
    string methodName;
    if (i_file.is_open()){
        while (getline(i_file,line)){
            istringstream iss(line);
            string token;
            while (getline(iss,token,'\t')){
                if (count==0){
                    methodName=token;
                    o_file<<"==="<<methodName<<"() method test==="<<endl;
                }
                if (token!=methodName){
                    o_file<<endl;
                    if (token!="addMovie" &&token!="deleteMovie" &&token!="addUser" &&token!="deleteUser"
                    &&token!="checkoutMovie" &&token!="showUser" &&token!="showMovie" && token!="returnMovie"){
                        o_file<<"===showAllMovie() method test==="<<endl;
                        methodName=token;
                    }else{
                        methodName=token;
                        o_file<<"==="<<token<<"() method test==="<<endl;

                    }


                }
                if(token=="addUser"){
                    getline(iss,token,'\t');
                    int id=stoi(token);
                    getline(iss,token,'\t');
                    addUser(id,token);
                }
                else if (token=="deleteUser"){
                    getline(iss,token,'\t');
                    int id=stoi(token);
                    deleteUser(id);
                }
                else if (token=="addMovie"){
                    getline(iss,token,'\t');
                    int id=stoi(token);
                    getline(iss,token,'\t');
                    string title=token;
                    getline(iss,token,'\t');
                    int year=stoi(token);
                    addMovie(id,title,year);
                }
                else if (token=="deleteMovie"){
                    getline(iss,token,'\t');
                    int id=stoi(token);
                    deleteMovie(id);
                }
                else if (token=="checkoutMovie"){
                    getline(iss,token,'\t');
                    int movieId=stoi(token);
                    getline(iss,token,'\t');
                    int userId=stoi(token);
                    checkoutMovie(movieId,userId);
                }
                else if (token=="showUser"){
                    getline(iss,token,'\t');
                    int id=stoi(token);
                    showUser(id);
                }
                else if (token=="showMovie"){
                    getline(iss,token,'\t');
                    int id=stoi(token);
                    showMovie(id);
                }
                else if (token=="showAllMovie\n" || token=="showAllMovie"){
                    showAllMovies();
                }
                else if (token=="returnMovie"){
                    getline(iss,token,'\t');
                    int id=stoi(token);
                    returnMovie(id);
                }
                else{
                    showAllMovies();
                }
                count=count+1;
            }
        }
    }
}





