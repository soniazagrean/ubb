template<typename TElem>
Set<TElem>::Set(Comparator<TElem> cmpFunc) : capacity(10), length(0), cmp(cmpFunc) {
    elems = new TElem[capacity];
}

template<typename TElem>
Set<TElem>::~Set() {
    delete[] elems;
}

template<typename TElem>
void Set<TElem>::resize() {
    capacity *= 2;
    TElem* newElems = new TElem[capacity];
    for (int i = 0; i < length; i++)
        newElems[i] = elems[i];
    delete[] elems;
    elems = newElems;
}

template<typename TElem>
int Set<TElem>::search(const TElem& e) const {
    for (int i = 0; i < length; i++) {
        if (!cmp(elems[i], e) && !cmp(e, elems[i]))
            return i;
    }
    return -1;
}

template<typename TElem>
void Set<TElem>::add(const TElem& e) {
    if (ifExists(e)) return;
    
    if (length == capacity) 
        resize();

    int pos = 0;
    while (pos < length && cmp(elems[pos], e))
        pos++;

    for (int i = length; i > pos; i--)
        elems[i] = elems[i - 1];
        
    elems[pos] = e;
    length++;
}

template<typename TElem>
bool Set<TElem>::remove(const TElem& e) {
    int pos = search(e);
    if (pos != -1) {
        for (int j = pos; j < length - 1; j++)
            elems[j] = elems[j + 1];
        length--;
        return true;
    }
    return false;
}

template<typename TElem>
bool Set<TElem>::ifExists(const TElem& e) const {
    return search(e) != -1;
}

template<typename TElem>
int Set<TElem>::size() const {
    return length;
}

template<typename TElem>
TElem Set<TElem>::getAt(int pos) const {
    if (pos < 0 || pos >= length)
        return TElem();
    return elems[pos];
}