/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SparseArray
*/

#ifndef SPARSEARRAY_HPP_
    #define SPARSEARRAY_HPP_
    #include <vector>

// template <typename Component> // You can also mirror the definition of std :: vector , that takes an additional allocator .
// class sparse_array {
//     public :
//         using value_type = Component; // optional component type
//         using reference_type = value_type &;
//         using const_reference_type = value_type const &;
//         using container_t = std::vector<value_type>; // optionally add your allocator template here .
//         using size_type = typename container_t::size_type;
//         using iterator = typename container_t::iterator;
//         using const_iterator = typename container_t::const_iterator;
//     public :
//         sparse_array (); // You can add more constructors .
//         sparse_array (sparse_array const &); // copy constructor
//         sparse_array (sparse_array &&) noexcept; // move constructor
//         ~sparse_array ();

//         sparse_array & operator =( sparse_array const &); // copy assignment operator
//         sparse_array & operator =( sparse_array &&) noexcept; // move assignment operator
//         reference_type operator []( size_t idx );
//         const_reference_type operator []( size_t idx ) const;

//         iterator begin ();
//         const_iterator begin() const;
//         const_iterator cbegin() const;

//         iterator end ();
//         const_iterator end() const;
//         const_iterator cend() const;

//         size_type size() const;
//         reference_type insert_at(size_type pos, Component const &);
//         reference_type insert_at(size_type pos, Component &&);

//         template < class ... Params >
//         reference_type emplace_at(size_type pos, Params &&...); // optional

//         void erase(size_type pos);

//         size_type get_index(value_type const &) const;
//     private :
//         container_t _data;
// };
// Feel free to add functions as needed. Most functions are straightforward, you just have to call the corre-
// sponding function of the underlying std::vector.
// Here are the functions you have to implement yourself:
// - insert_at: These functions should insert the component at a specific index, erasing the old value and re-
// sizing the vector if needed.
// - emplace_at: Same as insert_at, but the component is built in-place, or std::move’d into the container.
// - erase: Erase a value at a specified index.

template <typename T>
class SparseArray {
    public:
        using size_type = typename std::vector<T>::size_type;
        using iterator = typename std::vector<T>::iterator;
        using const_iterator = typename std::vector<T>::const_iterator;

        SparseArray();
        SparseArray(int entityNumber);
        SparseArray(SparseArray const & copy); // copy constructor
        SparseArray(SparseArray && move) noexcept; // move constructor
        ~SparseArray();

        SparseArray & operator =(SparseArray const &copy); // copy assignment operator
        SparseArray & operator =(SparseArray &&move) noexcept; // move assignment operator

        /**
         * @brief Gets the component value of type T from an entity with the specified ID.
         * @tparam T The type of the component's value.
         * @param index The index of the entity targeted.
         * @return reference to the Value of the component for the target.
         */
        T &operator [](int index);

        /**
         * @brief Gets the component value of type T from an entity with the specified ID.
         * @tparam T The type of the component's value.
         * @param index The index of the entity targeted.
         * @return Value const reference of the component for the target.
         */
        T const &operator [](int index) const;

        // iterator begin ();
        // const_iterator begin() const;
        // const_iterator cbegin() const;

        // iterator end ();
        // const_iterator end() const;
        // const_iterator cend() const;

        // size_type size() const;
        // T &insert_at(size_type pos, Component const &);
        // T &insert_at(size_type pos, Component &&);

        /**
         * @brief Add a new index to handle a new entity
         * @tparam T The type of the component's value.
         * @param index The index of the entity targeted.
         * @param component Value to apply.
         */
        void addEntity();

        /**
         * @brief Delete value at the index
         * @tparam T The type of the component's value.
         * @param index The index of the entity targeted.
         */
        void deleteEntity(int index);

        /**
         * @brief Change the component value from an entity with the specified ID.
         * @tparam T The type of the component's value.
         * @param index The index of the entity targeted.
         * @param component Value to apply.
         */
        void setComponentValue(int index, T component);

        /**
         * @brief Tells if the selected entity have the current component.
         * @param index The index of the entity targeted.
         * @return true if the component has a value false otherwise.
         */
        bool hasComponent(int index);

    protected:
    private:
        std::vector<T> _EntityList;
};

#endif /* !SPARSEARRAY_HPP_ */
