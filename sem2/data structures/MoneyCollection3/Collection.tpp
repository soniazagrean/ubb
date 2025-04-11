template <typename TElem>
void Collection<TElem>::resize() {
    this->capacity *= 2;
    auto* temp = new pairT<TElem>[this->capacity];
    for (int i = 0; i < this->len; i++)
        temp[i] = this->elems[i];
    delete[] this->elems;
    this->elems = temp;
}

template <typename TElem>
Collection<TElem>::Collection() {
    this->len = 0;
    this->capacity = 5;
    this->elems = new pairT<TElem>[this->capacity];
}

template <typename TElem>
Collection<TElem>::~Collection() {
    delete[] elems;
}

template <typename TElem>
void Collection<TElem>::loadBills() {
    delete[] this->elems;
    
    this->capacity = 5;
    this->len = 5;
    this->elems = new pairT<TElem>[this->capacity]{
        {2, 8}, {5, 2}, {10, 4}, {20, 2}, {50, 2}
    };
}

template <typename TElem>
void Collection<TElem>::add(TElem elem) {
    for (int i = 0; i < this->len; ++i)
        if (elem == elems[i].elem) {
            elems[i].freq++;
            return;
        }
    if (capacity == this->len)
        resize();
    elems[len] = pairT<TElem>{elem, 1};
    ++this->len;
}

template <typename TElem>
bool Collection<TElem>::remove(TElem elem, int freq) {
    for (int i = 0; i < this->len; i++) {
        if (elems[i].elem == elem) {
            if (freq > elems[i].freq)
                return false;
            elems[i].freq -= freq;
            if (elems[i].freq == 0) {
                for (int j = i + 1; j < this->len; j++) {
                    elems[j - 1] = elems[j];
                }
                len--;
            }
            return true;
        }
    }
    return false;
}

template <typename TElem>
bool Collection<TElem>::search(TElem elem) const {
    for (int i = 0; i < this->len; i++)
        if (elem == elems[i].elem)
            return true;
    return false;
}

template <typename TElem>
int Collection<TElem>::size() const {
    return len;
}

template <typename TElem>
int Collection<TElem>::nrOccurrences(TElem elem) const {
    for (int i = 0; i < len; i++)
        if (elem == elems[i].elem)
            return elems[i].freq;
    return 0;
}

template <typename TElem>
TElem Collection<TElem>::getAt(int position) const {
    if (position >= len || position < 0)
        return TElem();
    return elems[position].elem;
}

template <typename TElem>
void Collection<TElem>::printCollection() {
    for (int i = 0; i < this->len; ++i)
        std::cout << elems[i].elem << " x " << elems[i].freq << '\n';
}