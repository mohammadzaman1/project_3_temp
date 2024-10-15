#include "Kitchen.hpp"
#include <iostream>

int main(){
    Kitchen kitchen;
    Dish dish2("Tacos", {"Tortilla", "Beef", "Lettuce", "Tomato", "Cheese"}, 75, 8.0, Dish::CuisineType::MEXICAN);
    Dish dish3("Fried Rice", {"Rice", "Soy Sauce", "Vegetables", "Eggs"}, 10, 7.0, Dish::CuisineType::CHINESE);
    Dish dish4("Butter Chicken", {"Chicken", "Butter", "Tomato Sauce", "Cream"}, 10, 12.0, Dish::CuisineType::INDIAN);

    kitchen.newOrder(dish2);
    kitchen.newOrder(dish3);
    kitchen.newOrder(dish4);

    std::cout << kitchen.getCurrentSize() << std::endl;
    std::cout << kitchen.getPrepTimeSum() << std::endl;
    std::cout << kitchen.calculateAvgPrepTime() << std::endl;
    std::cout << kitchen.elaborateDishCount() << std::endl;
    std::cout << kitchen.calculateElaboratePercentage() << std::endl;
    std::cout << dish2.operator==(dish3) << std::endl;
    std::cout << dish2.operator!=(dish3) << std::endl;

    std::cout << '\n';
    kitchen.kitchenReport();
}