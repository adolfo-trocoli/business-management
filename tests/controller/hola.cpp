Controller.cpp: In member function ‘void Controller::lsEmployees()’:
Controller.cpp:30:17: error: ‘cout’ was not declared in this scope
   30 |                 cout << e->toString() << endl;
      |                 ^~~~
Controller.cpp:2:1: note: ‘std::cout’ is defined in header ‘<iostream>’; did you forget to ‘#include <iostream>’?
    1 | #include "Controller.h"
  +++ |+#include <iostream>
    2 | using namespace std;
Controller.cpp: In member function ‘void Controller::lsDepartments()’:
Controller.cpp:36:17: error: ‘cout’ was not declared in this scope
   36 |                 cout << d->toString() << endl;
      |                 ^~~~
Controller.cpp:36:17: note: ‘std::cout’ is defined in header ‘<iostream>’; did you forget to ‘#include <iostream>’?
In file included from ControllerTest.cpp:7:
../testConstants.h:7:1: error: expected ‘,’ or ‘;’ before ‘const’
    7 | const std::string EMPLOYEES_FILENAME = "test_temp_employees.txt";
      | ^~~~~
../testConstants.h:12:22: error: ‘EMPLOYEES_FILENAME’ was not declared in this scope
   12 | "\nemployee_file=" + EMPLOYEES_FILENAME +
      |                      ^~~~~~~~~~~~~~~~~~
In file included from /usr/include/c++/11/set:61,
                 from ControllerTest.cpp:12:
/usr/include/c++/11/bits/stl_set.h:64:1: error: expected ‘,’ or ‘;’ before ‘namespace’
   64 | namespace std _GLIBCXX_VISIBILITY(default)
      | ^~~~~~~~~
ControllerTest.cpp:19:111: error: ‘EMPLOYEES_FILENAME’ was not declared in this scope; did you mean ‘EMPLOYEES_FILE_CONTENT’?
   19 | std::unordered_map<std::string, std::string> CONFIG_PARAM_MAP{{"help_file", HELP_FILENAME}, {"employee_file", EMPLOYEES_FILENAME}, {"department_file", DEPARTMENTS_FILENAME}};
      |                                                                                                               ^~~~~~~~~~~~~~~~~~
      |                                                                                                               EMPLOYEES_FILE_CONTENT
ControllerTest.cpp:19:173: error: no matching function for call to ‘std::unordered_map<std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> >::unordered_map(<brace-enclosed initializer list>)’
   19 | std::unordered_map<std::string, std::string> CONFIG_PARAM_MAP{{"help_file", HELP_FILENAME}, {"employee_file", EMPLOYEES_FILENAME}, {"department_file", DEPARTMENTS_FILENAME}};
      |                                                                                                                                                                             ^
In file included from /usr/include/c++/11/unordered_map:47,
                 from /usr/include/c++/11/functional:61,
                 from /usr/include/c++/11/pstl/glue_algorithm_defs.h:13,
                 from /usr/include/c++/11/algorithm:74,
                 from /usr/include/c++/11/regex:38,
                 from DAO.h:6,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/bits/unordered_map.h:252:9: note: candidate: ‘template<class _InputIterator> std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map(_InputIterator, _InputIterator, std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type, const hasher&, const allocator_type&) [with _InputIterator = _InputIterator; _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  252 |         unordered_map(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:252:9: note:   template argument deduction/substitution failed:
ControllerTest.cpp:19:173: note:   candidate expects 5 arguments, 3 provided
   19 | std::unordered_map<std::string, std::string> CONFIG_PARAM_MAP{{"help_file", HELP_FILENAME}, {"employee_file", EMPLOYEES_FILENAME}, {"department_file", DEPARTMENTS_FILENAME}};
      |                                                                                                                                                                             ^
In file included from /usr/include/c++/11/unordered_map:47,
                 from /usr/include/c++/11/functional:61,
                 from /usr/include/c++/11/pstl/glue_algorithm_defs.h:13,
                 from /usr/include/c++/11/algorithm:74,
                 from /usr/include/c++/11/regex:38,
                 from DAO.h:6,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/bits/unordered_map.h:245:9: note: candidate: ‘template<class _InputIterator> std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map(_InputIterator, _InputIterator, std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type, const allocator_type&) [with _InputIterator = _InputIterator; _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  245 |         unordered_map(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:245:9: note:   template argument deduction/substitution failed:
ControllerTest.cpp:19:173: note:   candidate expects 4 arguments, 3 provided
   19 | std::unordered_map<std::string, std::string> CONFIG_PARAM_MAP{{"help_file", HELP_FILENAME}, {"employee_file", EMPLOYEES_FILENAME}, {"department_file", DEPARTMENTS_FILENAME}};
      |                                                                                                                                                                             ^
In file included from /usr/include/c++/11/unordered_map:47,
                 from /usr/include/c++/11/functional:61,
                 from /usr/include/c++/11/pstl/glue_algorithm_defs.h:13,
                 from /usr/include/c++/11/algorithm:74,
                 from /usr/include/c++/11/regex:38,
                 from DAO.h:6,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/bits/unordered_map.h:172:9: note: candidate: ‘template<class _InputIterator> std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map(_InputIterator, _InputIterator, std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type, const hasher&, const key_equal&, const allocator_type&) [with _InputIterator = _InputIterator; _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  172 |         unordered_map(_InputIterator __first, _InputIterator __last,
      |         ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:172:9: note:   template argument deduction/substitution failed:
ControllerTest.cpp:19:173: note:   couldn’t deduce template parameter ‘_InputIterator’
   19 | std::unordered_map<std::string, std::string> CONFIG_PARAM_MAP{{"help_file", HELP_FILENAME}, {"employee_file", EMPLOYEES_FILENAME}, {"department_file", DEPARTMENTS_FILENAME}};
      |                                                                                                                                                                             ^
In file included from /usr/include/c++/11/unordered_map:47,
                 from /usr/include/c++/11/functional:61,
                 from /usr/include/c++/11/pstl/glue_algorithm_defs.h:13,
                 from /usr/include/c++/11/algorithm:74,
                 from /usr/include/c++/11/regex:38,
                 from DAO.h:6,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/bits/unordered_map.h:264:7: note: candidate: ‘std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map(std::initializer_list<typename std::_Hashtable<_Key, std::pair<const _Key, _Tp>, _Alloc, std::__detail::_Select1st, _Pred, _Hash, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<std::__not_<std::__and_<std::__is_fast_hash<_Hash>, std::__is_nothrow_invocable<const _Hash&, const _Key&> > >::value, false, true> >::value_type>, std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type, const hasher&, const allocator_type&) [with _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >; typename std::_Hashtable<_Key, std::pair<const _Key, _Tp>, _Alloc, std::__detail::_Select1st, _Pred, _Hash, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<std::__not_<std::__and_<std::__is_fast_hash<_Hash>, std::__is_nothrow_invocable<const _Hash&, const _Key&> > >::value, false, true> >::value_type = std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type = long unsigned int; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::hasher = std::hash<std::__cxx11::basic_string<char> >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  264 |       unordered_map(initializer_list<value_type> __l,
      |       ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:264:7: note:   candidate expects 4 arguments, 3 provided
/usr/include/c++/11/bits/unordered_map.h:258:7: note: candidate: ‘std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map(std::initializer_list<typename std::_Hashtable<_Key, std::pair<const _Key, _Tp>, _Alloc, std::__detail::_Select1st, _Pred, _Hash, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<std::__not_<std::__and_<std::__is_fast_hash<_Hash>, std::__is_nothrow_invocable<const _Hash&, const _Key&> > >::value, false, true> >::value_type>, std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type, const allocator_type&) [with _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >; typename std::_Hashtable<_Key, std::pair<const _Key, _Tp>, _Alloc, std::__detail::_Select1st, _Pred, _Hash, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<std::__not_<std::__and_<std::__is_fast_hash<_Hash>, std::__is_nothrow_invocable<const _Hash&, const _Key&> > >::value, false, true> >::value_type = std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type = long unsigned int; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  258 |       unordered_map(initializer_list<value_type> __l,
      |       ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:258:50: note:   no known conversion for argument 1 from ‘<brace-enclosed initializer list>’ to ‘std::initializer_list<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >’
  258 |       unordered_map(initializer_list<value_type> __l,
      |                     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/11/bits/unordered_map.h:239:7: note: candidate: ‘std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map(std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type, const hasher&, const allocator_type&) [with _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type = long unsigned int; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::hasher = std::hash<std::__cxx11::basic_string<char> >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  239 |       unordered_map(size_type __n, const hasher& __hf,
      |       ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:239:31: note:   no known conversion for argument 1 from ‘<brace-enclosed initializer list>’ to ‘std::unordered_map<std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> >::size_type’ {aka ‘long unsigned int’}
  239 |       unordered_map(size_type __n, const hasher& __hf,
      |                     ~~~~~~~~~~^~~
/usr/include/c++/11/bits/unordered_map.h:235:7: note: candidate: ‘std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map(std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type, const allocator_type&) [with _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type = long unsigned int; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  235 |       unordered_map(size_type __n, const allocator_type& __a)
      |       ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:235:7: note:   candidate expects 2 arguments, 3 provided
/usr/include/c++/11/bits/unordered_map.h:227:7: note: candidate: ‘std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map(std::initializer_list<typename std::_Hashtable<_Key, std::pair<const _Key, _Tp>, _Alloc, std::__detail::_Select1st, _Pred, _Hash, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<std::__not_<std::__and_<std::__is_fast_hash<_Hash>, std::__is_nothrow_invocable<const _Hash&, const _Key&> > >::value, false, true> >::value_type>, std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type, const hasher&, const key_equal&, const allocator_type&) [with _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >; typename std::_Hashtable<_Key, std::pair<const _Key, _Tp>, _Alloc, std::__detail::_Select1st, _Pred, _Hash, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<std::__not_<std::__and_<std::__is_fast_hash<_Hash>, std::__is_nothrow_invocable<const _Hash&, const _Key&> > >::value, false, true> >::value_type = std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type = long unsigned int; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::hasher = std::hash<std::__cxx11::basic_string<char> >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::key_equal = std::equal_to<std::__cxx11::basic_string<char> >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  227 |       unordered_map(initializer_list<value_type> __l,
      |       ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:227:50: note:   no known conversion for argument 1 from ‘<brace-enclosed initializer list>’ to ‘std::initializer_list<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >’
  227 |       unordered_map(initializer_list<value_type> __l,
      |                     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~
/usr/include/c++/11/bits/unordered_map.h:210:7: note: candidate: ‘std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map(std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>&&, const allocator_type&) [with _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  210 |       unordered_map(unordered_map&& __umap,
      |       ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:210:7: note:   candidate expects 2 arguments, 3 provided
/usr/include/c++/11/bits/unordered_map.h:200:7: note: candidate: ‘std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map(const std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>&, const allocator_type&) [with _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  200 |       unordered_map(const unordered_map& __umap,
      |       ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:200:7: note:   candidate expects 2 arguments, 3 provided
/usr/include/c++/11/bits/unordered_map.h:191:7: note: candidate: ‘std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map(const allocator_type&) [with _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  191 |       unordered_map(const allocator_type& __a)
      |       ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:191:7: note:   candidate expects 1 argument, 3 provided
/usr/include/c++/11/bits/unordered_map.h:184:7: note: candidate: ‘std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map(std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>&&) [with _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  184 |       unordered_map(unordered_map&&) = default;
      |       ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:184:7: note:   candidate expects 1 argument, 3 provided
/usr/include/c++/11/bits/unordered_map.h:181:7: note: candidate: ‘std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map(const std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>&) [with _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  181 |       unordered_map(const unordered_map&) = default;
      |       ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:181:7: note:   candidate expects 1 argument, 3 provided
/usr/include/c++/11/bits/unordered_map.h:151:7: note: candidate: ‘std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map(std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type, const hasher&, const key_equal&, const allocator_type&) [with _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::size_type = long unsigned int; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::hasher = std::hash<std::__cxx11::basic_string<char> >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::key_equal = std::equal_to<std::__cxx11::basic_string<char> >; std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::allocator_type = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  151 |       unordered_map(size_type __n,
      |       ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:151:31: note:   no known conversion for argument 1 from ‘<brace-enclosed initializer list>’ to ‘std::unordered_map<std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> >::size_type’ {aka ‘long unsigned int’}
  151 |       unordered_map(size_type __n,
      |                     ~~~~~~~~~~^~~
/usr/include/c++/11/bits/unordered_map.h:141:7: note: candidate: ‘std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>::unordered_map() [with _Key = std::__cxx11::basic_string<char>; _Tp = std::__cxx11::basic_string<char>; _Hash = std::hash<std::__cxx11::basic_string<char> >; _Pred = std::equal_to<std::__cxx11::basic_string<char> >; _Alloc = std::allocator<std::pair<const std::__cxx11::basic_string<char>, std::__cxx11::basic_string<char> > >]’
  141 |       unordered_map() = default;
      |       ^~~~~~~~~~~~~
/usr/include/c++/11/bits/unordered_map.h:141:7: note:   candidate expects 0 arguments, 3 provided
ControllerTest.cpp:21:82: error: wrong number of template arguments (1, should be 3)
   21 | unordered_map<string, string> loadConfiguration(int argc, char** argv, set<string> configs);
      |                                                                                  ^
In file included from /usr/include/c++/11/set:62,
                 from ControllerTest.cpp:12:
/usr/include/c++/11/bits/stl_multiset.h:70:11: note: provided for ‘template<class _Key, class _Compare, class _Alloc> class std::set’
   70 |     class set;
      |           ^~~
ControllerTest.cpp: In function ‘void prepareTestFiles()’:
ControllerTest.cpp:75:21: error: ‘EMPLOYEES_FILENAME’ was not declared in this scope; did you mean ‘EMPLOYEES_FILE_CONTENT’?
   75 |     prepareTestFile(EMPLOYEES_FILENAME, EMPLOYEES_FILE_CONTENT);
      |                     ^~~~~~~~~~~~~~~~~~
      |                     EMPLOYEES_FILE_CONTENT
ControllerTest.cpp: In function ‘void removeTestFiles()’:
ControllerTest.cpp:92:12: error: ‘EMPLOYEES_FILENAME’ was not declared in this scope; did you mean ‘EMPLOYEES_FILE_CONTENT’?
   92 |     remove(EMPLOYEES_FILENAME.c_str());
      |            ^~~~~~~~~~~~~~~~~~
      |            EMPLOYEES_FILE_CONTENT
ControllerTest.cpp: In function ‘bool run_tests()’:
ControllerTest.cpp:102:34: error: ‘test_Employees’ was not declared in this scope; did you mean ‘test_findEmployees’?
  102 |     run_test("test_lsEmployees", test_Employees);
      |                                  ^~~~~~~~~~~~~~
      |                                  test_findEmployees
ControllerTest.cpp:103:36: error: ‘test_lsDepartments’ was not declared in this scope; did you mean ‘test_findDepartments’?
  103 |     run_test("test_lsDepartments", test_lsDepartments);
      |                                    ^~~~~~~~~~~~~~~~~~
      |                                    test_findDepartments
ControllerTest.cpp: In function ‘bool test_displayHelp()’:
ControllerTest.cpp:128:19: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  128 |     return assert(controller.displayHelp() == "<some help here>");
      |                   ^~~~~~~~~~
      |                   Controller
ControllerTest.cpp: In function ‘bool test_displaHelpCommand()’:
ControllerTest.cpp:132:19: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  132 |     return assert(controller.displayHelp("add") == "<some add help here>");
      |                   ^~~~~~~~~~
      |                   Controller
ControllerTest.cpp: In function ‘bool test_lsEmployees()’:
ControllerTest.cpp:140:5: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  140 |     controller.lsEmployees(); // Output goes to strCout
      |     ^~~~~~~~~~
      |     Controller
ControllerTest.cpp:142:20: error: no match for ‘operator<<’ (operand types are ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} and ‘std::__cxx11::basic_ostringstream<char>::__string_type’ {aka ‘std::__cxx11::basic_string<char>’})
  142 |     command_output << strCout.str();
      |     ~~~~~~~~~~~~~~ ^~ ~~~~~~~~~~~~~
      |     |                            |
      |     basic_string<[...]>          basic_string<[...]>
In file included from /usr/include/c++/11/regex:63,
                 from DAO.h:6,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/bits/regex.h:1649:5: note: candidate: ‘template<class _Ch_type, class _Ch_traits, class _Bi_iter> std::basic_ostream<_CharT, _Traits>& std::__cxx11::operator<<(std::basic_ostream<_CharT, _Traits>&, const std::__cxx11::sub_match<_Bi_iter>&)’
 1649 |     operator<<(basic_ostream<_Ch_type, _Ch_traits>& __os,
      |     ^~~~~~~~
/usr/include/c++/11/bits/regex.h:1649:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/bits/basic_string.h:48,
                 from /usr/include/c++/11/string:55,
                 from Department.h:3,
                 from ControllerTest.cpp:1:
/usr/include/c++/11/string_view:667:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, std::basic_string_view<_CharT, _Traits>)’
  667 |     operator<<(basic_ostream<_CharT, _Traits>& __os,
      |     ^~~~~~~~
/usr/include/c++/11/string_view:667:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/string:55,
                 from Department.h:3,
                 from ControllerTest.cpp:1:
/usr/include/c++/11/bits/basic_string.h:6531:5: note: candidate: ‘template<class _CharT, class _Traits, class _Alloc> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const std::__cxx11::basic_string<_CharT, _Traits, _Allocator>&)’
 6531 |     operator<<(basic_ostream<_CharT, _Traits>& __os,
      |     ^~~~~~~~
/usr/include/c++/11/bits/basic_string.h:6531:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/bits/ios_base.h:46,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/istream:38,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/system_error:279:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const std::error_code&)’
  279 |     operator<<(basic_ostream<_CharT, _Traits>& __os, const error_code& __e)
      |     ^~~~~~~~
/usr/include/c++/11/system_error:279:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:513:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, _CharT)’
  513 |     operator<<(basic_ostream<_CharT, _Traits>& __out, _CharT __c)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:513:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:518:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, char)’
  518 |     operator<<(basic_ostream<_CharT, _Traits>& __out, char __c)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:518:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:524:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, char)’
  524 |     operator<<(basic_ostream<char, _Traits>& __out, char __c)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:524:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<char, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:530:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, signed char)’
  530 |     operator<<(basic_ostream<char, _Traits>& __out, signed char __c)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:530:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<char, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:535:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, unsigned char)’
  535 |     operator<<(basic_ostream<char, _Traits>& __out, unsigned char __c)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:535:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<char, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:594:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const _CharT*)’
  594 |     operator<<(basic_ostream<_CharT, _Traits>& __out, const _CharT* __s)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:594:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/ostream:829,
                 from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/bits/ostream.tcc:321:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const char*)’
  321 |     operator<<(basic_ostream<_CharT, _Traits>& __out, const char* __s)
      |     ^~~~~~~~
/usr/include/c++/11/bits/ostream.tcc:321:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:611:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, const char*)’
  611 |     operator<<(basic_ostream<char, _Traits>& __out, const char* __s)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:611:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<char, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:624:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, const signed char*)’
  624 |     operator<<(basic_ostream<char, _Traits>& __out, const signed char* __s)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:624:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<char, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:629:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, const unsigned char*)’
  629 |     operator<<(basic_ostream<char, _Traits>& __out, const unsigned char* __s)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:629:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<char, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:750:5: note: candidate: ‘template<class _Ostream, class _Tp> _Ostream&& std::operator<<(_Ostream&&, const _Tp&)’
  750 |     operator<<(_Ostream&& __os, const _Tp& __x)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:750:5: note:   template argument deduction/substitution failed:
/usr/include/c++/11/ostream: In substitution of ‘template<class _Ostream, class _Tp> _Ostream&& std::operator<<(_Ostream&&, const _Tp&) [with _Ostream = std::__cxx11::basic_string<char>&; _Tp = std::__cxx11::basic_string<char>]’:
ControllerTest.cpp:142:35:   required from here
/usr/include/c++/11/ostream:750:5: error: no type named ‘type’ in ‘struct std::enable_if<false, void>’
In file included from /usr/include/c++/11/regex:39,
                 from DAO.h:6,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/bitset:1540:5: note: candidate: ‘template<class _CharT, class _Traits, long unsigned int _Nb> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const std::bitset<_Nb>&)’
 1540 |     operator<<(std::basic_ostream<_CharT, _Traits>& __os,
      |     ^~~~~~~~
/usr/include/c++/11/bitset:1540:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/memory:77,
                 from /usr/include/c++/11/regex:45,
                 from DAO.h:6,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/bits/shared_ptr.h:70:5: note: candidate: ‘template<class _Ch, class _Tr, class _Tp, __gnu_cxx::_Lock_policy _Lp> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const std::__shared_ptr<_Tp, _Lp>&)’
   70 |     operator<<(std::basic_ostream<_Ch, _Tr>& __os,
      |     ^~~~~~~~
/usr/include/c++/11/bits/shared_ptr.h:70:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:142:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  142 |     command_output << strCout.str();
      |                                   ^
ControllerTest.cpp: In function ‘bool test_lsDepartments()’:
ControllerTest.cpp:151:5: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  151 |     controller.lsDepartments(); // Output goes to strCout
      |     ^~~~~~~~~~
      |     Controller
ControllerTest.cpp:153:20: error: no match for ‘operator<<’ (operand types are ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} and ‘std::__cxx11::basic_ostringstream<char>::__string_type’ {aka ‘std::__cxx11::basic_string<char>’})
  153 |     command_output << strCout.str();
      |     ~~~~~~~~~~~~~~ ^~ ~~~~~~~~~~~~~
      |     |                            |
      |     basic_string<[...]>          basic_string<[...]>
In file included from /usr/include/c++/11/regex:63,
                 from DAO.h:6,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/bits/regex.h:1649:5: note: candidate: ‘template<class _Ch_type, class _Ch_traits, class _Bi_iter> std::basic_ostream<_CharT, _Traits>& std::__cxx11::operator<<(std::basic_ostream<_CharT, _Traits>&, const std::__cxx11::sub_match<_Bi_iter>&)’
 1649 |     operator<<(basic_ostream<_Ch_type, _Ch_traits>& __os,
      |     ^~~~~~~~
/usr/include/c++/11/bits/regex.h:1649:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/bits/basic_string.h:48,
                 from /usr/include/c++/11/string:55,
                 from Department.h:3,
                 from ControllerTest.cpp:1:
/usr/include/c++/11/string_view:667:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, std::basic_string_view<_CharT, _Traits>)’
  667 |     operator<<(basic_ostream<_CharT, _Traits>& __os,
      |     ^~~~~~~~
/usr/include/c++/11/string_view:667:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/string:55,
                 from Department.h:3,
                 from ControllerTest.cpp:1:
/usr/include/c++/11/bits/basic_string.h:6531:5: note: candidate: ‘template<class _CharT, class _Traits, class _Alloc> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const std::__cxx11::basic_string<_CharT, _Traits, _Allocator>&)’
 6531 |     operator<<(basic_ostream<_CharT, _Traits>& __os,
      |     ^~~~~~~~
/usr/include/c++/11/bits/basic_string.h:6531:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/bits/ios_base.h:46,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/istream:38,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/system_error:279:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const std::error_code&)’
  279 |     operator<<(basic_ostream<_CharT, _Traits>& __os, const error_code& __e)
      |     ^~~~~~~~
/usr/include/c++/11/system_error:279:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:513:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, _CharT)’
  513 |     operator<<(basic_ostream<_CharT, _Traits>& __out, _CharT __c)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:513:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:518:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, char)’
  518 |     operator<<(basic_ostream<_CharT, _Traits>& __out, char __c)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:518:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:524:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, char)’
  524 |     operator<<(basic_ostream<char, _Traits>& __out, char __c)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:524:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<char, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:530:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, signed char)’
  530 |     operator<<(basic_ostream<char, _Traits>& __out, signed char __c)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:530:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<char, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:535:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, unsigned char)’
  535 |     operator<<(basic_ostream<char, _Traits>& __out, unsigned char __c)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:535:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<char, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:594:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const _CharT*)’
  594 |     operator<<(basic_ostream<_CharT, _Traits>& __out, const _CharT* __s)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:594:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/ostream:829,
                 from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/bits/ostream.tcc:321:5: note: candidate: ‘template<class _CharT, class _Traits> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const char*)’
  321 |     operator<<(basic_ostream<_CharT, _Traits>& __out, const char* __s)
      |     ^~~~~~~~
/usr/include/c++/11/bits/ostream.tcc:321:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:611:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, const char*)’
  611 |     operator<<(basic_ostream<char, _Traits>& __out, const char* __s)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:611:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<char, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:624:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, const signed char*)’
  624 |     operator<<(basic_ostream<char, _Traits>& __out, const signed char* __s)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:624:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<char, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:629:5: note: candidate: ‘template<class _Traits> std::basic_ostream<char, _Traits>& std::operator<<(std::basic_ostream<char, _Traits>&, const unsigned char*)’
  629 |     operator<<(basic_ostream<char, _Traits>& __out, const unsigned char* __s)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:629:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<char, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/istream:39,
                 from /usr/include/c++/11/fstream:38,
                 from DAO.h:5,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/ostream:750:5: note: candidate: ‘template<class _Ostream, class _Tp> _Ostream&& std::operator<<(_Ostream&&, const _Tp&)’
  750 |     operator<<(_Ostream&& __os, const _Tp& __x)
      |     ^~~~~~~~
/usr/include/c++/11/ostream:750:5: note:   template argument deduction/substitution failed:
/usr/include/c++/11/ostream: In substitution of ‘template<class _Ostream, class _Tp> _Ostream&& std::operator<<(_Ostream&&, const _Tp&) [with _Ostream = std::__cxx11::basic_string<char>&; _Tp = std::__cxx11::basic_string<char>]’:
ControllerTest.cpp:153:35:   required from here
/usr/include/c++/11/ostream:750:5: error: no type named ‘type’ in ‘struct std::enable_if<false, void>’
In file included from /usr/include/c++/11/regex:39,
                 from DAO.h:6,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/bitset:1540:5: note: candidate: ‘template<class _CharT, class _Traits, long unsigned int _Nb> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const std::bitset<_Nb>&)’
 1540 |     operator<<(std::basic_ostream<_CharT, _Traits>& __os,
      |     ^~~~~~~~
/usr/include/c++/11/bitset:1540:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
In file included from /usr/include/c++/11/memory:77,
                 from /usr/include/c++/11/regex:45,
                 from DAO.h:6,
                 from DepartmentDAO.h:4,
                 from ControllerTest.cpp:2:
/usr/include/c++/11/bits/shared_ptr.h:70:5: note: candidate: ‘template<class _Ch, class _Tr, class _Tp, __gnu_cxx::_Lock_policy _Lp> std::basic_ostream<_CharT, _Traits>& std::operator<<(std::basic_ostream<_CharT, _Traits>&, const std::__shared_ptr<_Tp, _Lp>&)’
   70 |     operator<<(std::basic_ostream<_Ch, _Tr>& __os,
      |     ^~~~~~~~
/usr/include/c++/11/bits/shared_ptr.h:70:5: note:   template argument deduction/substitution failed:
ControllerTest.cpp:153:35: note:   ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’} is not derived from ‘std::basic_ostream<_CharT, _Traits>’
  153 |     command_output << strCout.str();
      |                                   ^
ControllerTest.cpp:154:37: error: ‘DEPARTMENTºS_FILE_CONTENT’ was not declared in this scope; did you mean ‘DEPARTMENTS_FILE_CONTENT’?
  154 |     return assert(command_output == DEPARTMENTºS_FILE_CONTENT);
      |                                     ^~~~~~~~~~~~~~~~~~~~~~~~~
      |                                     DEPARTMENTS_FILE_CONTENT
ControllerTest.cpp: In function ‘bool test_findEmployee()’:
ControllerTest.cpp:160:29: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  160 |     optional<Employee*> e = controller.findEmployee(10);
      |                             ^~~~~~~~~~
      |                             Controller
ControllerTest.cpp: In function ‘bool test_findEmployees()’:
ControllerTest.cpp:166:35: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  166 |     vector<Employee*> employees = controller.findEmployees();
      |                                   ^~~~~~~~~~
      |                                   Controller
ControllerTest.cpp:168:12: error: ‘employeess’ was not declared in this scope; did you mean ‘employees’?
  168 |         if(employeess[i-1]->getId() != i){
      |            ^~~~~~~~~~
      |            employees
ControllerTest.cpp: In function ‘bool test_createEmployee()’:
ControllerTest.cpp:176:8: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  176 |     if(controller.createEmployee("Employee<Non-existent-dpt-id>", 100)) return fail();
      |        ^~~~~~~~~~
      |        Controller
ControllerTest.cpp:177:5: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  177 |     controller.createEmployee("Employee<Valid>", 5);
      |     ^~~~~~~~~~
      |     Controller
ControllerTest.cpp: In function ‘bool test_removeEmployee()’:
ControllerTest.cpp:183:5: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  183 |     controller.removeEmployee(1);
      |     ^~~~~~~~~~
      |     Controller
ControllerTest.cpp:185:8: error: ‘emp’ was not declared in this scope
  185 |     if(emp.has_value()) return fail();
      |        ^~~
ControllerTest.cpp: In function ‘bool test_updateEmployee()’:
ControllerTest.cpp:190:8: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  190 |     if(controller.updateEmployee(9, "Employee.Invalid-DptId", 700)) return fail();
      |        ^~~~~~~~~~
      |        Controller
ControllerTest.cpp:191:9: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  191 |     if(!controller.updateDepartment(9, "Employee.Valid", 2)) return fail();
      |         ^~~~~~~~~~
      |         Controller
ControllerTest.cpp:192:31: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  192 |     optional<Employee*> emp = controller.findEmployee(9);
      |                               ^~~~~~~~~~
      |                               Controller
ControllerTest.cpp: In function ‘bool test_findDepartment()’:
ControllerTest.cpp:200:31: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  200 |     optional<Department*> e = controller.findDepartment(10);
      |                               ^~~~~~~~~~
      |                               Controller
ControllerTest.cpp: In function ‘bool test_findDepartments()’:
ControllerTest.cpp:206:39: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  206 |     vector<Department*> departments = controller.findDepartments();
      |                                       ^~~~~~~~~~
      |                                       Controller
ControllerTest.cpp: In function ‘bool test_createDepartment()’:
ControllerTest.cpp:214:8: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  214 |     if(controller.createDepartment("Department<Non-existent-manager-id>", 1000, 696)) return fail();
      |        ^~~~~~~~~~
      |        Controller
ControllerTest.cpp:215:5: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  215 |     controller.createDepartment("Department<Valid>", 1000, 5);
      |     ^~~~~~~~~~
      |     Controller
ControllerTest.cpp: In function ‘bool test_removeDepartment()’:
ControllerTest.cpp:221:5: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  221 |     controller.removeDepartment(1);
      |     ^~~~~~~~~~
      |     Controller
ControllerTest.cpp: In function ‘bool test_updateDepartment()’:
ControllerTest.cpp:227:8: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  227 |     if(controller.updateDepartment(9, "Dpt.Invalid-ManagerId", 700)) return fail();
      |        ^~~~~~~~~~
      |        Controller
ControllerTest.cpp:228:9: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  228 |     if(!controller.updateDepartment(9, "Dpt.UpdateDepartment", 2)) return fail();
      |         ^~~~~~~~~~
      |         Controller
ControllerTest.cpp:229:33: error: ‘controller’ was not declared in this scope; did you mean ‘Controller’?
  229 |     optional<Department*> dpt = controller.findDepartment(9);
      |                                 ^~~~~~~~~~
      |                                 Controller
