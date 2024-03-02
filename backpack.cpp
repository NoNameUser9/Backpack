//
// Created by User on 19.02.2024.
//

#include "backpack.h++"

Backpack::Backpack()
{
    capacity_ = 0;
}

Backpack::Backpack(unsigned size)
{
    capacity_ = size;
}

void
Backpack::resize(unsigned size)
{
    capacity_ = size;
}

unsigned
Backpack::size() const
{
    return capacity_;
}

/// \brief knapsack problem with costs and weights and unlimited number of elements
/// \return max costs by set capacity
unsigned
Backpack::sort_unlim()
{
    unsigned n = items_.size();
    std::vector<std::vector<unsigned >> dp(n + 1, std::vector<unsigned >(capacity_ + 1, 0));

    for (unsigned i = 1; i <= n; i++)
        for (unsigned w = 1; w <= capacity_; ++w)
            if (items_[i - 1].weight <= w)
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - items_[i - 1].weight] + items_[i - 1].cost);
            else
                dp[i][w] = dp[i - 1][w];

    return dp[n][capacity_];

//        for(unsigned i = 1; i < nn - 1; ++i){
//            for(unsigned j = 0; j < w; ++j){
//                dp[i][j] = dp[i - 1][j];
//                if(items_[i]->weight <= j)
//                    dp[i][j] = std::max(dp[i][j], dp[i][j - items_[i]->weight] + items_[i]->cost);
//            }
//        }
}

/// \brief don't work now
/// \param k - max number of items
/// \return weight
/// \note Doesn't work correctly right now
unsigned
Backpack::sort_lim(unsigned k)
{
    unsigned n = items_.size();
    std::vector<std::vector<unsigned >> dp(n + 1, std::vector<unsigned >(capacity_ + 1, 0));

    for (unsigned i = 1; i <= n; i++) {
        for (unsigned w = 1; w <= capacity_; w++) {
            if (items_[i - 1].weight <= w) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - items_[i - 1].weight] + items_[i - 1].cost);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity_];
}

/// \remark prints all elements of this class
void
Backpack::print()
{
    unsigned t_size = 0;

    while(t_size < items_.size())
        std::cout << "Content: " << items_[t_size].content << "\nweight: " << items_[t_size].weight << "\ncost: "
                  << items_[t_size++].cost << "\n\n";
}

void
Backpack::add(Item *item)
{
    items_.emplace_back(item->content, item->weight, item->cost);
}
