void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int partition(int a[],int low,int high)
{
  int pivot = a[high];
  int i=(low-1);
  for(int j=low;j<=(high-1);j++)
  {
    if(a[j]<=pivot)
    {
      i++;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[high],&a[i+1]);
  return (i+1);

}
void qs(int a[],int low,int high)
{
  if(low<high)
  {
    int pi = partition(a,low,high);
    qs(a,low,pi-1);
    qs(a,pi+1,high);
  }
}
