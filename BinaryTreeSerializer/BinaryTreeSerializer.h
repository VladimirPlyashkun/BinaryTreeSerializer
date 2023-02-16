#ifndef BINARYTREESERIALIZER_H
#define BINARYTREESERIALIZER_H

#include "BinaryTree.h"
#include <string>
#include <queue>

namespace Serialization {
    class BinaryTreeSerializer {
    public:
        [[nodiscard]]
        std::string toString(const DataStructures::BinaryTreeNode *node);

        [[nodiscard]]
        DataStructures::BinaryTreeNode *fromString(const std::string &input);

    private:
        void append(std::string &output, const std::string &whatAppend);

        std::queue<std::string> splitString(const std::string &input);

        DataStructures::BinaryTreeNode *makeTree(std::queue<std::string> &values);
    };
}

#endif //BINARYTREESERIALIZER_H
