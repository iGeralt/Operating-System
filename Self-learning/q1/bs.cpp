int Search(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return Search(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return Search(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int binarySearch(int arr[], int l, int n, int x)
{
	int i, j;
	for (i = 0; i < n-1; i++)
	   // Last i elements are already in place
	   for (j = 0; j < n-i-1; j++)
	       if (arr[j] > arr[j+1])
	          swap(&arr[j], &arr[j+1]);
	Search(arr,l,n-1,x);
}
