

#pragma once
#include <vector>
#include <optional>
#include <memory>

namespace Algorithm::DataStructure
{
    class DoubleLinkedList
    {
    public:
        struct DoubleLinkedList_Node;
        using spNode = std::shared_ptr<DoubleLinkedList_Node>;
        using wpNode = std::weak_ptr<DoubleLinkedList_Node>;

        struct DoubleLinkedList_Node
        {
            int data{};
            wpNode previous{};
            spNode next{};
        };
        

        static auto test();

        explicit DoubleLinkedList(const std::vector<int> &ivec);

        auto head()const{return _spHead;}
        
    private:
        spNode _spHead{};

    };

}