#include "BinaryTreeSerializer.h"

std::string Serialization::BinaryTreeSerializer::toString(const DataStructures::BinaryTreeNode *node) {
    if (node == nullptr) {
        return "null";
    }
    std::string output;
    output += std::to_string(node->value);
    append(output, toString(node->left));
    append(output, toString(node->right));
    return output;
}

DataStructures::BinaryTreeNode *Serialization::BinaryTreeSerializer::fromString(const std::string &input) {
    std::queue<std::string> values = splitString(input);
    return makeTree(values);
}

void Serialization::BinaryTreeSerializer::append(std::string &output, const std::string &whatAppend) {
    if (!output.empty() && output[output.size() - 1] != ' ') {
        output.push_back(' ');
    }
    output += whatAppend;
}

std::queue<std::string> Serialization::BinaryTreeSerializer::splitString(const std::string &input) {
    std::queue<std::string> values;
    std::string currentValue;
    for (int i = 0; i < input.size(); ++i) {
        char c = input[i];
        if (c != ' ') {
            currentValue.push_back(c);
            continue;
        }
        values.push(currentValue);
        currentValue.clear();
    }
    if (!currentValue.empty()) {
        values.push(currentValue);
    }
    return values;
}

DataStructures::BinaryTreeNode *Serialization::BinaryTreeSerializer::makeTree(std::queue<std::string> &values) {
    if (values.empty()) {
        return nullptr;
    }
    std::string valueStr = values.front();
    values.pop();
    if (valueStr == "null") {
        return nullptr;
    }
    int value = std::stoi(valueStr);
    auto node = new DataStructures::BinaryTreeNode{value};
    node->left = makeTree(values);
    node->right = makeTree(values);
    return node;
}

