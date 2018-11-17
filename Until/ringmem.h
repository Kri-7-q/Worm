#ifndef RINGMEM_H
#define RINGMEM_H


template<class T>
class RingMem
{
public:
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
      \brief Delete the allocated Array.
     */
    ~RingMem()
    {
        delete [] m_pArray;
    }

    void add(const T& element);

    /*!
     * \brief Get an Element at the given index.
     * \param index     The 0 based index of Elemenet.
     * \return T&       The Element at index.
     */
    T& at(const unsigned index) const               { return m_pArray[(m_head + index) % m_currentSize]; }

    /*!
     * \brief Operator overlaod operator []
     *        Same as at() method.
     * \param index     The 0 based index of Element.
     * \return T&       The Element at index.
     */
    T& operator [] (const unsigned index) const     { at(index); }

private:
    const unsigned m_size;
    unsigned m_currentSize;
    unsigned m_head;
    T* m_pArray;
};



/*!
 * \brief Add a new element at the head (first position). If ring is full
 *        the last element will be deleted.
 * \param element
 */
template<class T>
void RingMem<T>::add(const T& element) {
    if (m_currentSize < 1) {
        m_pArray[m_head] = element;
        ++m_currentSize;
        return;
    }
    if (m_currentSize < m_size) {
        --m_head;
        m_pArray[m_head] = element;
        ++m_currentSize;
    } else {
        m_head = (m_head - 1 + m_size) % m_size;
        m_pArray[m_head] = element;
    }
}

#endif // RINGMEM_H
