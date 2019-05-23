struct _List_node_base {
  _List_node_base* _M_next;
  _List_node_base* _M_prev;
};

template <class _Tp>
struct _List_node : public _List_node_base {
  _Tp _M_data;
};

struct _List_iterator_base {
  typedef int                     size_type;

  _List_node_base* _M_node;

  _List_iterator_base(_List_node_base* __x) : _M_node(__x) {}
  _List_iterator_base() {}

  void _M_incr() { _M_node = _M_node->_M_next; }
  void _M_decr() { _M_node = _M_node->_M_prev; }

  bool operator==(const _List_iterator_base& __x) const {
    return _M_node == __x._M_node;
  }
  bool operator!=(const _List_iterator_base& __x) const {
    return _M_node != __x._M_node;
  }
};

template<class _Tp>
struct _List_iterator : public _List_iterator_base {
  typedef _List_iterator<_Tp>             iterator;
  typedef _List_iterator<_Tp>             _Self;

  typedef _Tp value_type;
  typedef _List_node<_Tp> _Node;

  _List_iterator(_Node* __x) : _List_iterator_base(__x) {}
  _List_iterator() {}
  _List_iterator(const iterator& __x) : _List_iterator_base(__x._M_node) {}

  _Tp operator*() const { return ((_Node*) _M_node)->_M_data; }

  _Self& operator++() {
    this->_M_incr();
    return *this;
  }
  _Self operator++(int) {
    _Self __tmp = *this;
    this->_M_incr();
    return __tmp;
  }
  _Self& operator--() {
    this->_M_decr();
    return *this;
  }
  _Self operator--(int) {
    _Self __tmp = *this;
    this->_M_decr();
    return __tmp;
  }
};

template <class _Tp>
class _List_base
{
public:

  _List_base() {
    _M_node = new _List_node<_Tp>();
    _M_node->_M_next = _M_node;
    _M_node->_M_prev = _M_node;
  }
  ~_List_base() {
    clear();
    _M_put_node(_M_node);
  }

  void clear();

protected:

protected:
  _List_node<_Tp>* _M_node;
};


template <class _Tp>
void
_List_base<_Tp>::clear()
{
  _List_node<_Tp>* __cur = (_List_node<_Tp>*) _M_node->_M_next;
  while (__cur != _M_node) {
    _List_node<_Tp>* __tmp = __cur;
    __cur = (_List_node<_Tp>*) __cur->_M_next;
    _Destroy(&__tmp->_M_data);
    _M_put_node(__tmp);
  }
  _M_node->_M_next = _M_node;
  _M_node->_M_prev = _M_node;
}

template <class _Tp>
class list : protected _List_base<_Tp> {
  // requirements:

  typedef _List_base<_Tp> _Base;
protected:
//   typedef void* _Void_pointer;

public:
  typedef _Tp value_type;
//   typedef value_type* pointer;
//   typedef const value_type* const_pointer;
  typedef value_type& reference;
//   typedef const value_type& const_reference;
  typedef _List_node<_Tp> _Node;
  typedef size_t size_type;

  typedef typename _Base::allocator_type allocator_type;
  allocator_type get_allocator() const { return _Base::get_allocator(); }

public:
  typedef _List_iterator<_Tp>             iterator;

protected:
  _Node* _M_create_node(const _Tp& __x)
  {
    _Node* __p = new _Node();
    new ((void*) &__p->_M_data) _T1(__x);
    return __p;
  }

  _Node* _M_create_node()
  {
    _Node* __p = new _Node();
    new ((void*) &__p->_M_data) _T1();
    return __p;
  }

public:
//   explicit list(const allocator_type& __a = allocator_type()) : _Base(__a) {}

  iterator begin()             { return (_Node*)(_M_node->_M_next); }

  iterator end()             { return _M_node; }


  bool empty() const { return _M_node->_M_next == _M_node; }
  size_type size() const {
    size_type __result = 0;
    distance(begin(), end(), __result);
    return __result;
  }
  size_type max_size() const { return size_type(-1); }

  reference front() { return *begin(); }
  reference back() { return *(--end()); }

  iterator insert(iterator __position, const _Tp& __x) {
    _Node* __tmp = _M_create_node(__x);
    __tmp->_M_next = __position._M_node;
    __tmp->_M_prev = __position._M_node->_M_prev;
    __position._M_node->_M_prev->_M_next = __tmp;
    __position._M_node->_M_prev = __tmp;
    return __tmp;
  }

  void push_front(const _Tp& __x) { insert(begin(), __x); }
  void push_back(const _Tp& __x) { insert(end(), __x); }

  iterator erase(iterator __position) {
    _List_node_base* __next_node = __position._M_node->_M_next;
    _List_node_base* __prev_node = __position._M_node->_M_prev;
    _Node* __n = (_Node*) __position._M_node;
    __prev_node->_M_next = __next_node;
    __next_node->_M_prev = __prev_node;
    _Tp* point = &__n->_M_data;
    point->~_Tp();
    delete __n;
    return iterator((_Node*) __next_node);
  }
  void clear() { _Base::clear(); }

  void pop_front() { erase(begin()); }
  void pop_back() {
    iterator __tmp = end();
    erase(--__tmp);
  }
  list(): _Base() {}
  ~list() { }
};

template <class _Tp>
inline bool
operator==(const list<_Tp>& __x, const list<_Tp>& __y)
{
  typedef typename list<_Tp>::iterator const_iterator;
  const_iterator __end1 = __x.end();
  const_iterator __end2 = __y.end();

  const_iterator __i1 = __x.begin();
  const_iterator __i2 = __y.begin();
  while (__i1 != __end1 && __i2 != __end2 && *__i1 == *__i2) {
    ++__i1;
    ++__i2;
  }
  return __i1 == __end1 && __i2 == __end2;
}

template <class _Tp>
list<_Tp>& list<_Tp>::operator=(const list<_Tp>& __x)
{
  if (this != &__x) {
    iterator __first1 = begin();
    iterator __last1 = end();
    const_iterator __first2 = __x.begin();
    const_iterator __last2 = __x.end();
    while (__first1 != __last1 && __first2 != __last2)
      *__first1++ = *__first2++;
    if (__first2 == __last2)
      erase(__first1, __last1);
    else
      insert(__last1, __first2, __last2);
  }
  return *this;
}


