
#include "BinaryTree.h"
#include "BinaryTreeSerializer.h"

#include <iostream>

int main() {

    //input string format example: "1 2 3 null null 4 null null 5 null null"
    std::string input;
    std::getline(std::cin, input);

    Serialization::BinaryTreeSerializer serializer;
    auto node = serializer.fromString(input);

    std::string output = serializer.toString(node);

    std::cout << output;

    return 0;
}
