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

unsigned int
Backpack::size() const
{
    return capacity_;
}

/// \brief knapsack problem with costs and weights and unlimited number of elements
/// \return max costs by set capacity
unsigned int
Backpack::sort_with_costs()
{
    unsigned n = items_.size();
    std::vector<std::vector<unsigned>> dp(n + 1, std::vector<unsigned>(capacity_ + 1, 0));

    for (unsigned i = 1; i <= n; i++)
        for (unsigned j = 1; j <= capacity_; ++j)
            if (items_[i - 1].weight <= j)
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - items_[i - 1].weight] + items_[i - 1].cost);
            else
                dp[i][j] = dp[i - 1][j];

    return dp[n][capacity_];
}

/// \brief don't work now
/// \return weight
/// \note Doesn't work correctly right now
unsigned int
Backpack::sort_lim()
{
    unsigned n = items_.size();
    std::vector<std::vector<unsigned>> dp(n + 1, std::vector<unsigned>(capacity_ + 1, 0));

    for (unsigned i = 1; i <= n; ++i)
        for (unsigned j = 1; j <= capacity_; ++j)
            for (unsigned k = 0; k <= items_[i - 1].quantity; ++k)
                if (k * items_[i - 1].weight <= j)
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - k * items_[i - 1].weight] + k * items_[i - 1].cost);

    return dp[n][capacity_];
}

unsigned int
Backpack::sort_unlim()
{
    unsigned n = items_.size();
    std::vector<unsigned> dp(capacity_ + 1, 0);

    for (int w = 1; w <= capacity_; w++)
    {
        for (int i = 0; i < n; i++)
        {
            if (items_[i].weight <= w)
            {
                dp[w] = std::max(dp[w], dp[w - items_[i].weight] + items_[i].cost);
            }
        }
    }

    return dp[capacity_];
}

/// \remark prints all elements of this class
void
Backpack::print()
{
    unsigned t_size = 0;

    while (t_size < items_.size())
        std::cout << "Content: " << items_[t_size].content << "\nweight: " << items_[t_size].weight << "\ncost: "
                  << items_[t_size++].cost << "\n\n";
}

void
Backpack::add(const Item& item)
{
    items_.emplace_back(item);
}
