typedef struct		s_list			//название структуры
{
	void			*content;		//данные, содержащиеся в ссылке. Пустота * позволяет хранить любые данные.
	size_t			content_size; 
	struct s_list	*next;			//адресс следующей ссылке 
}					t_list;			// то как мы обращаемся !


void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst && del)
	{
		del((*alst)->content, (*alst)->content_size_t)
		free(*alst);
		*alst = NULL;
	}
}
Принимает в качестве параметра адрес указателя ссылки и освобождает память содержимого ссылки с помощью функции del, заданной в качестве параметра, затем освобождает память связи с помощью free. Память о следующем не должна быть освобождена ни при каких обстоятельствах.

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst && del)
	{
		while (*alst)
		{
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = (*alst)->next;
		}
		*alst = NULL;
	}
}

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst   // делаем счетчик только зачем делаем присвоение ? 
		*alst = new;      //присваиваем значения alst новому листу!
//		return ;         -- зачем он нужен 
	}
}

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list newlist;

	if (!lst && !f)
		return (NULL);
	if (lst)
	{
		newlist = f(lst);
		newlist->next = ft_lstmap(next->lst, f); // -почему мы применяем функию в конце если она применяеться выше !
		return (newlist)
	}
	return (NULL);
}



















