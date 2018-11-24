#ifndef RINGMEM_H
#define RINGMEM_H


template<class T>
class RingMem
{
public:
    /*!
     * \brief Standard Constructor
     * \warning DELETED
     */
    RingMem() = delete;

    /*!
     * \brief Creates a RingMem object with given size.
     * \param maxSize
     * \param currentSize
     */
    RingMem(const unsigned size) :
        m_size(size),
        m_currentSize(0),
        m_head(size-1),
        m_pArray(new T[size])
    {

    }

    /*!
     * \brief Copy constructor
     *        Makes a deep copy of object other.
     * \param other
     */
    RingMem(const RingMem& other) :
        m_size(other.m_size),
        m_currentSize(other.m_currentSize),
        m_head(other.m_head),
        m_pArray(new T[m_size])
    {
        copyArray(other.m_pArray);
    }

    /*!
     * \brief Move constructor
     * \param other
     */
    RingMem(RingMem&& other) :
        m_size(other.m_size),
        m_currentSize(other.m_currentSize),
        m_head(other.m_head),
        m_pArray(other.m_pArray)
    {
        other.erase(false);             // Contant array is copied to the other object. Do not delete.
    }

    /*!
      \brief Delete the allocated Array.
     */
    ~RingMem()
    {
        delete [] m_pArray;
    }

    unsigned totalSize() const              { return m_size; }
    unsigned currentSize() const            { return m_currentSize; }
    void add(const T& element);
    void increaseTo(const unsigned size);

    /*!
     * \brief Get an Element at the given index.
     * \param index     The 0 based index of Elemenet.
     * \return T&       The Element at index.
     */
    T& at(const unsigned index) const               { return m_pArray[(m_head + index) % m_currentSize]; }

    // -------      Operator overloads      ----------
    /*!
     * \brief Operator << overload
     *        Same as add(). Adds an element to the ring.
     * \param element The new element to add to the ring.
     * \return this A reference to this object for method caining.
     */
    RingMem& operator << (const T& element)         { add(element); return *this; }

    /*!
     * \brief Operator overlaod operator []
     *        Same as at() method.
     * \param index     The 0 based index of Element.
     * \return T&       The Element at index.
     */
    T& operator [] (const unsigned index) const     { return at(index); }

protected:
    inline void copyArray(const T* const pSource);
    inline void copyRingDataTo(RingMem<T> &other);
    inline void erase(const bool deleteHeap = true);
    // --------     Operator overload       ----------
    RingMem<T>& operator = (RingMem<T>&& rhs);

private:
    unsigned m_size;
    unsigned m_currentSize;
    unsigned m_head;
    T* m_pArray;
};



/*!
 * \brief Add a new element at the head (first position). If ring is full
 *        the last element will be deleted.
 *        Appends an element and overrides the last if ring is full.
 * \param element
 */
template<class T>
void RingMem<T>::add(const T& element) {
    if (m_currentSize < 1) {                // Insert first element.
        m_pArray[m_head] = element;
        ++m_currentSize;
        return;
    }
    if (m_currentSize < m_size) {           // Array has empty space.
        --m_head;
        m_pArray[m_head] = element;
        ++m_currentSize;
    } else {                                // Array is full. MUST override an older object.
        m_head = (m_head - 1 + m_size) % m_size;
        m_pArray[m_head] = element;
    }
}

/*!
 * \brief PROTECTED
 *        Copy the content of pSource to this objects array.
 *        This method was implemented for the copy constructor.
 * \param pSource   A pointer to a source array which is to be copied.
 */
template<class T>
void RingMem<T>::copyArray(const T* const pSource) {
    for (unsigned index=0; index<m_size; ++index) {
        m_pArray[index] = pSource[index];
    }
}

/*!
 * \brief Increase ring size to given size. If size is lower then current ring size
 *        then nothing will happen.
 * \param size  The new size of the ring memory.
 */
template<class T>
void RingMem<T>::increaseTo(const unsigned size) {
    if (m_size >= size) {
        return;
    }
    RingMem<T> tmpRing(size);
    copyRingDataTo(tmpRing);
    *this = static_cast<RingMem<T>&&>(tmpRing);
}

/*!
 * \brief PROTECTED
 *        Move operator =
 * \param rhs   RingMem object of which contant is moved to another object.
 * \return this A reference to this RingMem object.
 */
template<class T>
RingMem<T>& RingMem<T>::operator = (RingMem<T>&& rhs) {
    m_size = rhs.m_size;
    m_currentSize = rhs.m_currentSize;
    m_head = rhs.m_head;
    delete [] m_pArray;
    m_pArray = rhs.m_pArray;

    rhs.erase(false);           // Contant array is copied to this ring. Do not delete.

    return *this;
}

/*!
 * \brief Erase this object. Sets all values to null and delete heap memory.
 * \param deleteHeap    If true array in heap will be deleted. True is standard.
 */
template<class T>
void RingMem<T>::erase(const bool deleteHeap) {
    m_size = 0;
    m_currentSize = 0;
    m_head = 0;
    if (deleteHeap)
        delete [] m_pArray;
    m_pArray = nullptr;
}

/*!
 * \brief RingMem<T>::copyRingData
 * \param other
 */
template<class T>
void RingMem<T>::copyRingDataTo(RingMem<T>& other) {
    unsigned index=m_currentSize;
    do {
        --index;
        other << at(index);
    } while (index > 0);
}

#endif // RINGMEM_H
