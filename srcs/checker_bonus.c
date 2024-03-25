#include "checker.h"
#include "../libasm/libasm.h"

int intcmp(void *a, void *b)
{
	return ((long int)a - (long int)b);
}

int uintcmp(void *a, void *b)
{
	return ((unsigned int)(a - b));
}

int is_sorted(t_list *list, int (*cmp)())
{
	while (list && list->next)
	{
		if (cmp(list->data, list->next->data) > 0)
			return (0);
		list = list->next;
	}
	return (1);
}

void	free_data(void *data)
{
	(void)data;
	return ;
}

int	main(void)
{
	{	// FT_ATOI_BASE
		ASSERT(ft_atoi_base("", "0123456789") == 0);
		ASSERT(ft_atoi_base("---", "0123456789") == 0);
		ASSERT(ft_atoi_base("+++", "0123456789") == 0);
		ASSERT(ft_atoi_base("+-+--+-++-", "0123456789") == 0);
		ASSERT(ft_atoi_base("    +-0", "0123456789") == 0);
		ASSERT(ft_atoi_base("    +1", "0123456789") == 1);
		ASSERT(ft_atoi_base("    -1", "0123456789") == -1);

		ASSERT(ft_atoi_base("42", "0") == 0);
		ASSERT(ft_atoi_base("42", "0 1") == 0);
		ASSERT(ft_atoi_base("42", "01-23456789") == 0);
		ASSERT(ft_atoi_base("42", "012345+6789") == 0);
		ASSERT(ft_atoi_base("42", "0123456789 ") == 0);
		ASSERT(ft_atoi_base("42", "01223456789") == 0);

		ASSERT(ft_atoi_base("42", "0123456789") == 42);
		ASSERT(ft_atoi_base("deadcafe", "0123456789abcdef") == (int)0xdeadcafe);
		ASSERT(ft_atoi_base("101010", "01") == 42);
		ASSERT(ft_atoi_base("052", "01234567") == 42);

		ASSERT(ft_atoi_base("+2147483647", "0123456789") == +2147483647);
		ASSERT(ft_atoi_base("-2147483648", "0123456789") == -2147483648);

		printf("\033[32m[+] ft_atoi_base\n\033[0m");
	}

	{	// FT_LIST_PUSH_FRONT
		t_list	*list;
		t_list	*tmp;

		list = NULL;
		ft_list_push_front(&list, (void *)42);
		ASSERT(list != NULL);
		ASSERT(list->data == (void *)42);
		ASSERT(list->next == NULL);

		tmp = list;
		ft_list_push_front(&list, (void *)104);
		ASSERT(list != NULL);
		ASSERT(list->data == (void *)104);
		ASSERT(list->next != NULL);
		ASSERT(list->next == tmp);
		ASSERT(list->next->data == (void *)42);
		ASSERT(list->next->next == NULL);

		free(list->next);
		free(list);

		printf("\033[32m[+] ft_list_push_front\n\033[0m");
	}

	{	// FT_LIST_SIZE
		t_list	*list;
		t_list	*tmp;

		list = NULL;
		ASSERT(ft_list_size(list) == 0);

		ft_list_push_front(&list, (void *)42);
		ASSERT(ft_list_size(list) == 1);

		ft_list_push_front(&list, (void *)104);
		ASSERT(ft_list_size(list) == 2);

		tmp = list->next;
		list->next = NULL;
		ASSERT(ft_list_size(list) == 1);

		free(tmp);
		free(list);

		printf("\033[32m[+] ft_list_size\n\033[0m");
	}

	{	// FT_LIST_SORT
		t_list	*list1;
		t_list	*list2;
		t_list	*list3;
		t_list	*list4;
		t_list	*tmp;

		list1 = NULL;
		ft_list_push_front(&list1, (void *)1);
		ft_list_push_front(&list1, (void *)2);
		ft_list_push_front(&list1, (void *)3);
		ft_list_sort(&list1, intcmp);
		ASSERT(ft_list_size(list1) == 3);
		ASSERT(is_sorted(list1, intcmp));

		list2 = NULL;
		ft_list_push_front(&list2, (void *)-7);
		ft_list_push_front(&list2, (void *)42);
		ft_list_push_front(&list2, (void *)0);
		ft_list_sort(&list2, intcmp);
		ASSERT(ft_list_size(list2) == 3);
		ASSERT(is_sorted(list2, intcmp));

		list3 = NULL;
		ft_list_push_front(&list3, (void *)2);
		ft_list_push_front(&list3, (void *)3);
		ft_list_push_front(&list3, (void *)2);
		ft_list_push_front(&list3, (void *)1);
		ft_list_sort(&list3, intcmp);
		ASSERT(ft_list_size(list3) == 4);
		ASSERT(is_sorted(list3, intcmp));

		list4 = NULL;
		ft_list_push_front(&list4, (void *)"never");
		ft_list_push_front(&list4, (void *)"gonna");
		ft_list_push_front(&list4, (void *)"give");
		ft_list_push_front(&list4, (void *)"you");
		ft_list_push_front(&list4, (void *)"up");
		ft_list_sort(&list4, strcmp);
		ASSERT(ft_list_size(list4) == 5);
		ASSERT(is_sorted(list4, strcmp));

		while (list1) { tmp = list1->next; free(list1); list1 = tmp; }
		while (list2) { tmp = list2->next; free(list2); list2 = tmp; }
		while (list3) { tmp = list3->next; free(list3); list3 = tmp; }
		while (list4) { tmp = list4->next; free(list4); list4 = tmp; }

		printf("\033[32m[+] ft_list_sort\n\033[0m");
	}

	{	// FT_LIST_REMOVE_IF
		t_list	*list1;
		t_list	*list2;
		t_list	*list3;
		t_list	*list4;
		t_list	*tmp;

		list1 = NULL;
		ft_list_push_front(&list1, (void *)3);
		ft_list_push_front(&list1, (void *)2);
		ft_list_push_front(&list1, (void *)1);
		ASSERT(ft_list_size(list1) == 3);
		ft_list_remove_if(&list1, (void *)3, uintcmp, free_data);
		ASSERT(ft_list_size(list1) == 2);
		ASSERT(list1->data == (void *)1);
		ASSERT(list1->next->data == (void *)2);
		ASSERT(list1->next->next == NULL);

		list2 = NULL;
		ft_list_push_front(&list2, (void *)1);
		ft_list_push_front(&list2, (void *)2);
		ft_list_push_front(&list2, (void *)3);
		ASSERT(ft_list_size(list2) == 3);
		ft_list_remove_if(&list2, (void *)1, uintcmp, free_data);
		ASSERT(ft_list_size(list2) == 2);
		ASSERT(list2->data == (void *)3);
		ASSERT(list2->next->data == (void *)2);
		ASSERT(list2->next->next == NULL);

		list3 = NULL;
		ft_list_push_front(&list3, (void *)3);
		ft_list_push_front(&list3, (void *)2);
		ft_list_push_front(&list3, (void *)2);
		ft_list_push_front(&list3, (void *)2);
		ft_list_push_front(&list3, (void *)1);
		ASSERT(ft_list_size(list3) == 5);
		ft_list_remove_if(&list3, (void *)2, uintcmp, free_data);
		ASSERT(ft_list_size(list3) == 2);
		ASSERT(list3->data == (void *)1);
		ASSERT(list3->next->data == (void *)3);
		ASSERT(list3->next->next == NULL);

		list4 = NULL;
		ft_list_push_front(&list4, (void *)1);
		ft_list_push_front(&list4, (void *)1);
		ft_list_push_front(&list4, (void *)1);
		ASSERT(ft_list_size(list4) == 3);
		ft_list_remove_if(&list4, (void *)1, uintcmp, free_data);
		ASSERT(ft_list_size(list4) == 0);
		ASSERT(list4 == NULL);

		while (list1) { tmp = list1->next; free(list1); list1 = tmp; }
		while (list2) { tmp = list2->next; free(list2); list2 = tmp; }
		while (list3) { tmp = list3->next; free(list3); list3 = tmp; }
		while (list4) { tmp = list4->next; free(list4); list4 = tmp; }

		printf("\033[32m[+] ft_list_remove_if\n\033[0m");
	}

	return (0);
}