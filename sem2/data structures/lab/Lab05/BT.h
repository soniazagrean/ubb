#pragma once
#include <stdexcept>

template <typename TElem>
using PFunction = void(*)(TElem);

template <typename TElem>
class BT {
private:
    static const int VALUE_MAX = 100;

    TElem tree[VALUE_MAX];
    bool exists[VALUE_MAX];   // heap based implementation/bitmask
    const int root = 0;

    void visitPreorder(int index, PFunction<TElem> f) const {
        if (index >= VALUE_MAX || !exists[index])
            return;

        f(tree[index]);
        visitPreorder(2 * index + 1, f);
        visitPreorder(2 * index + 2, f);
    }

    void copySubtree(const BT& source, int src, int dest) {
        if (!source.exists[src])
            return;

        tree[dest] = source.tree[src];
        exists[dest] = true;

        copySubtree(source, 2 * src + 1, 2 * dest + 1);
        copySubtree(source, 2 * src + 2, 2 * dest + 2);
    }


public:
    BT() {
        for (int i = 0; i < VALUE_MAX; ++i)
            exists[i] = false;
    }

    ~BT()=default;

    bool empty() const {
        return exists[root] == 0;
    }

    void createLeaf(TElem elem) {
        tree[root] = elem;
        exists[root] = true;
    }

    TElem elem() const {
        if (empty())
            throw std::runtime_error("empty");
        return tree[root];
    }

    void addSubtreeLeft(const BT& leftTree) {
        copySubtree(leftTree, 0, 2 * root + 1);
    }

    void addSubtreeRight(const BT& rightTree) {
        copySubtree(rightTree, 0, 2 * root + 2);
    }

    BT left() const {
        BT result;

        for (int i = 0; i + 2 * root + 1 < VALUE_MAX; ++i) {
            if (exists[2 * root + 1 + i]) {
                result.tree[i] = tree[2 * root + 1 + i];
                result.exists[i] = true;
            }
        }

        return result;
    }

    BT right() const {
        BT result;

        for (int i = 0; i + 2 * root + 2 < VALUE_MAX; ++i) {
            if (exists[2 * root + 2 + i]) {
                result.tree[i] = tree[2 * root + 2 + i];
                result.exists[i] = true;
            }
        }

        return result;
    }

    void visitTree(PFunction<TElem> f) const {
        visitPreorder(root, f);
    }

};