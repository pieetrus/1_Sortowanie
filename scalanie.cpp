#include "scalanie.hh"

template <class typ>
void scal(typ *tab, int low, int high, int mid)
{
	int i, j, k;
	typ * temp = new typ[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= high)
	{
		if (tab[i] < tab[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = tab[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = tab[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		temp[k] = tab[j];
		k++;
		j++;
	}


	for (i = low; i <= high; i++)
	{
		tab[i] = temp[i-low];
	}
        delete [] temp;
}

template <class typ>
void sortowanie_scalanie(int *tab, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		sortowanie_scalanie<typ>(tab, low, mid);
		sortowanie_scalanie<typ>(tab, mid+1, high);

		scal<typ>(tab, low, high, mid);
	}
}
