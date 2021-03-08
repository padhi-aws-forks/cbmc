void assigns_range(int a[], int len) __CPROVER_assigns(a[0, len]);

void assigns_range(int a[], int len)
{
  int i;
  while (0 <= i && i <= len) {
    a[i] = 100;
    i++;
  }
}

int main()
{
  int arr[11];
  assigns_range(arr, 10);

  return 0;
}
