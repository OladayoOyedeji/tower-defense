#ifndef PRIORITY_H
#define PRIORITY_H

#include <vector>

template <typename T>
class PriorityQueue
{
  public:
    PriorityQueue()
    {}
    PriorityQueue(bool (*comp)(T , T ))
        : cmp(comp)
    {}
    PriorityQueue(const PriorityQueue & q)
        : pq_(q.pq_)
    {}
    PriorityQueue(const std::vector<T> & v)
        : pq_(v)
    {
        maxheap_build(pq_);
    }

    // heap functions
    int left(int i) const
    {
        return 2 * i + 1;
    }
    int right(int i) const
    {
        return 2 * i + 2;
    }
    int parent(int i) const
    {
        return (i - 2) / 2;
    }
    void heapify_up(int i)
    {
        T t = pq_[i];
    
        while (1)
        {
            int p = parent(i);
            if (p < 0)
            {
                pq_[i] = t;
                break;
            }
            if (cmp(t, pq_[p]))
            {
                pq_[i] = pq_[p];
                i = p;
            }
            else
            {
                pq_[i] = t;
                break;
            }
        }
    }
    void heapify_down(int i)
    {
        T t = pq_[i];
        int j;
        while (1)
        {
            int l = left(i);
            int r = right(i);
            if (l >= pq_.size())
            {
                j = l;
            }
            else
            {
                if (r >= pq_.size())
                {
                    j = l;
                }
                else if (cmp(pq_[l], pq_[r]))
                {
                    j = l;
                }
                else
                {
                    j = r;
                }
            }
            if (j < pq_.size() && cmp(pq_[j], t))
            {
                pq_[i] = pq_[j];
                i = j;
            }
            else
            {
                pq_[i] = t;
                break;
            }
        }
    }
    void heap_buld()
    {
        for (int i = pq_.size()/2; i >= 0; --i)
        {
            maxheap_heapify_down(pq_, i);
        }
    }
    
    
    void insert(const T & value)
    {
        pq_.push_back(value);
        
        heapify_up(pq_.size() - 1);
        
    }
    void delete_(int i)
    {
        pq_[i] = pq_[pq_.size() - 1];
        pq_.resize(pq_.size() - 1);

        heapify_down(i);
        
    }
    T delete_root()
    {
        T v = pq_[0];
        delete_(0);
        return pq_;
    }
    T & max()
    {
        return pq_[0];
    }
    void clear()
    {
        pq_.clear();
    }
    int size() const
    {
        return pq_.size();
    }
    bool is_empty() const
    {
        return (pq_.size() == 0);
    }
    void operator=(const PriorityQueue & q)
    {
        pq_ = q.pq_;
    }
    bool operator==(const PriorityQueue & q)
    {
        if (pq_.size() != q.size())
        {
            return false;
        }
        for (int i = 0; i < pq_.size(); ++i)
        {
            if (pq_[i] != q.pq_[i])
                return false;
        }
        return true;
    }
    void print()const
    {
        std::cout << pq_;
    }
  private:
    std::vector<T> pq_;
    bool (*cmp)(const T , const T );
};

template <typename T>
std::ostream & operator<<(std::ostream & cout, const PriorityQueue<T> & v)
{
    v.print();
    return cout;
}

#endif
