# Libft

**Version: October 2021**

Libft used for each project **after** the [`libft`](https://github.com/mlrcbsousa/libft) project.

## Quick Links

### Part 1

<a href="/ft_memset.c" target="_blank">

- ```c
  void	*ft_memset(void *str, int c, size_t n);
  ```
</a>
<a href="/ft_bzero.c" target="_blank">

- ```c
  void	ft_bzero(void *s, size_t n);
  ```
</a>
<a href="/ft_memcpy.c" target="_blank">

- ```c
  void	*ft_memcpy(void *dest, const void *src, size_t n);
  ```
</a>
<a href="/ft_memccpy.c" target="_blank">

- ```c
  void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
  ```
</a>
<a href="/ft_memmove.c" target="_blank">

- ```c
  void	*ft_memmove(void *dest, const void *src, size_t n);
  ```
</a>
<a href="/ft_memchr.c" target="_blank">

- ```c
  void	*ft_memchr(const void *str, int c, size_t n);
  ```
</a>
<a href="/ft_memcmp.c" target="_blank">

- ```c
  int	ft_memcmp(const void *str1, const void *str2, size_t n);
  ```
</a>
<a href="/ft_strlen.c" target="_blank">

- ```c
  size_t	ft_strlen(const char *str);
  ```
</a>
<a href="/ft_strlcpy.c" target="_blank">

- ```c
  size_t	ft_strlcpy(char *dst, const char *src, size_t size);
  ```
</a>
<a href="/ft_strlcat.c" target="_blank">

- ```c
  size_t	ft_strlcat(char *dst, const char *src, size_t size);
  ```
</a>
<a href="/ft_strchr.c" target="_blank">

- ```c
  char	*ft_strchr(const char *str, int c);
  ```
</a>
<a href="/ft_strrchr.c" target="_blank">

- ```c
  char	*ft_strrchr(const char *str, int c);
  ```
</a>
<a href="/ft_strnstr.c" target="_blank">

- ```c
  char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
  ```
</a>
<a href="/ft_strncmp.c" target="_blank">

- ```c
  int	ft_strncmp(const char *s1, const char *s2, size_t n);
  ```
</a>
<a href="/ft_atoi.c" target="_blank">

- ```c
  int	ft_atoi(const char *str);
  ```
</a>
<a href="/ft_isalpha.c" target="_blank">

- ```c
  int	ft_isalpha(int c);
  ```
</a>
<a href="/ft_isdigit.c" target="_blank">

- ```c
  int	ft_isdigit(int c);
  ```
</a>
<a href="/ft_isalnum.c" target="_blank">

- ```c
  int	ft_isalnum(int c);
  ```
</a>
<a href="/ft_isascii.c" target="_blank">

- ```c
  int	ft_isascii(int c);
  ```
</a>
<a href="/ft_isprint.c" target="_blank">

- ```c
  int	ft_isprint(int c);
  ```
</a>
<a href="/ft_toupper.c" target="_blank">

- ```c
  int	ft_toupper(int c);
  ```
</a>
<a href="/ft_tolower.c" target="_blank">

- ```c
  int	ft_tolower(int c);
  ```
</a>
<a href="/ft_calloc.c" target="_blank">

- ```c
  void	*ft_calloc(size_t nmemb, size_t size);
  ```
</a>
<a href="/ft_strdup.c" target="_blank">

- ```c
  char	*ft_strdup(const char *s1);
  ```

### Part 2

<a href="/ft_substr.c" target="_blank">

- ```c
  char	*ft_substr(char const *s, unsigned int start, size_t len);
  ```
</a>
<a href="/ft_strjoin.c" target="_blank">

- ```c
  char	*ft_strjoin(char const *s1, char const *s2);
  ```
</a>
<a href="/ft_strtrim.c" target="_blank">

- ```c
  char	*ft_strtrim(char const *s1, char const *set);
  ```
</a>
<a href="/ft_split.c" target="_blank">

- ```c
  char	**ft_split(char const *s, char c);
  ```
</a>
<a href="/ft_itoa.c" target="_blank">

- ```c
  char	*ft_itoa(int n);
  ```
</a>
<a href="/ft_strmapi.c" target="_blank">

- ```c
  char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
  ```
</a>
<a href="/ft_putchar_fd.c" target="_blank">

- ```c
  void	ft_putchar_fd(char c, int fd);
  ```
</a>
<a href="/ft_putstr_fd.c" target="_blank">

- ```c
  void	ft_putstr_fd(char const *s, int fd);
  ```
</a>
<a href="/ft_putendl_fd.c" target="_blank">

- ```c
  void	ft_putendl_fd(char const *s, int fd);
  ```
</a>
<a href="/ft_putnbr_fd.c" target="_blank">

- ```c
  void	ft_putnbr_fd(int nb, int fd);
  ```

### Bonus

<a href="/ft_lstnew.c" target="_blank">

- ```c
  t_list	*ft_lstnew(void *content);
  ```
</a>
<a href="/ft_lstadd_front.c" target="_blank">

- ```c
  void	ft_lstadd_front(t_list **lst, t_list *new);
  ```
</a>
<a href="/ft_lstsize.c" target="_blank">

- ```c
  int	ft_lstsize(t_list *lst);
  ```
</a>
<a href="/ft_lstlast.c" target="_blank">

- ```c
  t_list	*ft_lstlast(t_list *lst);
  ```
</a>
<a href="/ft_lstadd_back.c" target="_blank">

- ```c
  void	ft_lstadd_back(t_list **lst, t_list *new);
  ```
</a>
<a href="/ft_lstdelone.c" target="_blank">

- ```c
  void	ft_lstdelone(t_list *lst, void (*del)(void *));
  ```
</a>
<a href="/ft_lstclear.c" target="_blank">

- ```c
  void	ft_lstclear(t_list **lst, void (*del)(void	*));
  ```
</a>
<a href="/ft_lstiter.c" target="_blank">

- ```c
  void	ft_lstiter(t_list *lst, void (*f)(void *));
  ```
</a>
<a href="/ft_lstmap.c" target="_blank">

- ```c
  t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
  ```

### Added

<a href="/ft_strcpy.c" target="_blank">

- ```c
  char	*ft_strcpy(char *dst, const char *src);
  ```
</a>
<a href="/ft_strnchr.c" target="_blank">

- ```c
  int	ft_strnchr(const char *str, int c);
  ```
</a>
<a href="/ft_isspace.c" target="_blank">

- ```c
  int	ft_isspace(char c);
  ```
</a>
<a href="/ft_uitoa.c" target="_blank">

- ```c
  char	*ft_uitoa(unsigned int n);
  ```
</a>
<a href="/get_next_line.c" target="_blank">

- ```c
  int	get_next_line(int fd, char **line);
  ```
</a>
<a href="/ft_ternary.c" target="_blank">

- ```c
  int	ft_ternary(int condition, int a, int b);
  ```
</a>
<a href="/ft_abs.c" target="_blank">

- ```c
  int	ft_abs(int n);
  ```
</a>
<a href="/ft_ullen.c" target="_blank">

- ```c
  size_t	ft_ullen(unsigned long nbr);
  ```
</a>
<a href="/ft_ullen_base.c" target="_blank">

- ```c
  size_t	ft_ullen_base(unsigned long nbr, int base);
  ```
</a>
<a href="/ft_putnbr_base.c" target="_blank">

- ```c
  void	ft_putnbr_base(long long nb, char *radix);
  ```
</a>
<a href="/ft_putchar.c" target="_blank">

- ```c
  void	ft_putchar(char c);
  ```
</a>
<a href="/ft_putstr.c" target="_blank">

- ```c
  void	ft_putstr(char *str);
  ```
</a>
<a href="/ft_ultoa_base.c" target="_blank">

- ```c
  char	*ft_ultoa_base(unsigned long n, char *radix);
  ```
</a>

