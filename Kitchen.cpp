/**
 * @file Kitchen.cpp
 * @brief This file contains the implementation of the Dish class, which represents a dish in a virtual bistro simulation.
 *
 * 
 * @date 10/05/2024
 * @author Mohammad Zaman
 */

#include "Kitchen.hpp"

//Default constructor
Kitchen::Kitchen() : total_prep_time_(0), count_elaborate_(0) {}

//Unique functions

bool Kitchen::newOrder(const Dish& new_dish) {
    if (contains(new_dish))
    {
        return false;
    }
    else{
        add(new_dish);
        total_prep_time_+=new_dish.getPrepTime();
        if (new_dish.getPrepTime()>=60 && (new_dish.getIngredients()).size()>=5){
            count_elaborate_++;
        }
        return true;
    }
}

bool Kitchen::serveDish(const Dish& dish){
    if(remove(dish)){
        total_prep_time_-=dish.getPrepTime();
        if (dish.getPrepTime()>=60 && (dish.getIngredients()).size()>=5){
            count_elaborate_--;
        }
        return true;
    }
    else{
        return false;
    }
}

int Kitchen::getPrepTimeSum() const{
    return total_prep_time_;
}

int Kitchen::calculateAvgPrepTime() const
{
    if (isEmpty())
    {
        return 0; // checks if kitchen is empty
    }
    else
    {
        return round((double(total_prep_time_) / getCurrentSize())); // turns the division result into a double then rounds it.
    }
}

int Kitchen::elaborateDishCount() const{
    return count_elaborate_;
}

double Kitchen::calculateElaboratePercentage() const{
    if (isEmpty())
    {
        return 0;
    }
    else
    {
        double per = (double(count_elaborate_) / getCurrentSize()) * 100; // calculates the percantage
        return (round(per * 100.0) / 100.0);                              // rounds it to 2 decimal place
    }
}

int Kitchen::tallyCuisineTypes(const std::string& cuisine_type) const {
    int count = 0;
    for (int i = 0; i<item_count_; i++){
        if (items_[i].getCuisineType() == cuisine_type){
            count++;
        }
    }
    return count;
}

int Kitchen::releaseDishesBelowPrepTime(const int& prep_time){
    int count = 0;
    for(int i=0; i<item_count_;i++){
        if(items_[i].getPrepTime()<prep_time){
            remove(items_[i]);
            count++;
        }
    }
    return count;
}

int Kitchen::releaseDishesOfCuisineType(const std::string& cuisine_type){
    int count = 0;
    for(int i=0; i<item_count_;i++){
        if(items_[i].getCuisineType() == cuisine_type){
            remove(items_[i]);
            count++;
        }
    }
    return count;
}

void Kitchen::kitchenReport() const{
    std::cout<<"ITALIAN: " << ("ITALIAN")<<std::endl;
    std::cout<<"MEXICAN: " << tallyCuisineTypes("MEXICAN")<<std::endl;
    std::cout<<"CHINESE: " << tallyCuisineTypes("CHINESE")<<std::endl;
    std::cout<<"INDIAN: " << tallyCuisineTypes("INDIAN")<<std::endl;
    std::cout<<"AMERICAN: " << tallyCuisineTypes("AMERICAN")<<std::endl;
    std::cout<<"FRENCH: " << tallyCuisineTypes("FRENCH")<<std::endl;
    std::cout<<"OTHER: " << tallyCuisineTypes("OTHER")<<std::endl;
    std::cout<<"\n";
    std::cout<< "AVERAGE PREP TIME: "<< calculateAvgPrepTime()<<std::endl;
    std::cout<< "ELABORATE DISHES: "<< calculateElaboratePercentage() << "%" <<std::endl;
}






