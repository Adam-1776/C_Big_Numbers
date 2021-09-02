#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int intal_compare(const char * intal1,const char * intal2){
  int l1 = strlen(intal1);
  int l2 = strlen(intal2);
  if (l1 > l2) return 1;
  if (l2 > l1) {
    return -1;
  }
  int i = 0;
  for (i = 0; i < l1; ++i) {
    if (intal1[i] > intal2[i]) return 1;
    if (intal2[i] > intal1[i]) return -1;
  }
  return 0;
}
char * intal_add(const char * intal1,const char * intal2) {
  int count = 0;
  int i = 0;
  int n1 = strlen(intal1);
  int n2 = strlen(intal2);
  if (n2 < n1) return intal_add(intal2, intal1);
  char * str2 = malloc(sizeof(char) * (n2 + 2));
  int diff = n2 - n1;
  char str[1001] = {
    0
  };
  int sum = 0;
  int carry = 0;
  for (i = n1 - 1; i >= 0; --i) {
    sum = ((intal1[i] - '0') + (intal2[i + diff] - '0') + carry);
    str[count] = (sum % 10 + '0');
    ++count;
    carry = sum / 10;
  }
  for (int i = n2 - n1 - 1; i >= 0; --i) {
    sum = ((intal2[i] - '0') + carry);
    str[count] = (sum % 10 + '0');
    ++count;
    carry = sum / 10;
  }
  if (carry) {
    str[count] = (carry + '0');
    ++count;
  }
  str[count] = '\0';
  sum = 0;
  for (i = (count - 1); i >= 0; --i) {
    str2[sum] = str[i];
    ++sum;
  }
  str2[count] = '\0';
  return str2;
}
char * intal_diff(const char * intal1,
  const char * intal2) {
  if (intal_compare(intal1, intal2) == -1) {
    return intal_diff(intal2, intal1);
  }
  if (intal_compare(intal1, intal2) == 0) {
    char * ans = malloc(sizeof(char) * 2);
    ans[0] = 48;
    ans[1] = '\0';
    return ans;
  }
  int l1 = strlen(intal1);
  int l2 = strlen(intal2);
  int carry = 0;
  char * ans = malloc(sizeof(char) * (l1 + 1));
  int diff = l1 - l2;
  int i = 0;
  int y = 0;
  for (i = l2 - 1; i >= 0; --i) {
    int sub = ((intal1[i + diff] - 48) - (intal2[i] - 48) - carry);
    if (sub < 0) {
      sub = sub + 10;
      carry = 1;
    } else carry = 0;
    ans[y] = (sub + 48);
    ++y;
  }
  for (i = l1 - l2 - 1; i >= 0; --i) {
    if (intal1[i] == 48 && carry) {
      ans[y] = 57;
      ++y;
      continue;
    }
    int sub = ((intal1[i] - 48) - carry);
    if (i > 0 || sub > 0) {
      ans[y] = (sub + 48);
    }++y;
    carry = 0;
  }
  ans[y] = '\0';
  i = y - 1;
  while (ans[i] == 48) {
    ans[i] = '\0';
    --i;
  }
  int len = strlen(ans);
  if (len > 1) {
    char * ans2 = malloc(sizeof(char) * (len + 1));
    y = 0;
    for (i = len - 1; i >= 0; --i) {
      ans2[y] = ans[i];
      ++y;
    }
    ans2[y] = '\0';
    free(ans);
    return ans2;
  } else {
    ans[1] = '\0';
    return ans;
  }
}
char * intal_multiply(const char * intal1,const char * intal2) {
  int j = 0;
  if (strcmp(intal1, "0") == 0 || strcmp(intal2, "0") == 0) {
    char * ans = malloc(sizeof(char) * 2);
    ans[0] = 48;
    ans[1] = '\0';
    return ans;
  }
  int l1 = strlen(intal1);
  int l2 = strlen(intal2);
  int n1 = 0;
  int * ans = malloc(sizeof(int) * (l1 + l2 + 1));
  int i_n1 = 0;
  int i_n2 = 0;
  int i = 0;
  int carry = 0;
  int n2 = 0;
  int sum = 0;
  for (i = 0; i < (l1 + l2 + 1); ++i) ans[i] = 0;
  for (i = l1 - 1; i >= 0; --i) {
    carry = 0;
    n1 = intal1[i] - 48;
    i_n2 = 0;
    for (j = l2 - 1; j >= 0; --j) {
      n2 = intal2[j] - 48;
      sum = n1 * n2 + ans[i_n1 + i_n2] + carry;
      carry = sum / 10;
      ans[i_n1 + i_n2] = sum % 10;
      ++i_n2;
    }
    if (carry > 0) ans[i_n1 + i_n2] += carry;
    ++i_n1;
  }
  char * ans2 = malloc(sizeof(char) * (l1 + l2 + 1));
  int len = l1 + l2;
  while (len >= 0 && ans[len] == 0) --len;
  j = 0;
  while (len >= 0) {
    ans2[j] = 48 + ans[len--];
    ++j;
  }
  ans2[j] = '\0';
  free(ans);
  return ans2;
}
char * intal_mod(const char * intal1, const char * intal2) {
  if (strcmp(intal2, "1") == 0 || strcmp(intal2, "0") == 0) {
    char * ans = malloc(sizeof(char) * 2);
    ans[0] = 48;
    ans[1] = '\0';
    return ans;
  }
  int l1 = strlen(intal1);
  if (intal_compare(intal1, intal2) == -1) {
    char * ans = malloc(sizeof(char) * (1 + l1));
    strcpy(ans, intal1);
    return ans;
  }
  char * temp = malloc(sizeof(char) * (l1 + 2));
  strcpy(temp, intal2);
  int b = 0;
  char * temp2 = malloc(sizeof(char) * (l1 + 2));
  char * temp3 = malloc(sizeof(char) * (l1 + 2));
  char * tmp;
  strcpy(temp2, temp);
  strcpy(temp3, temp2);
  while (1) {
    strcpy(temp2, temp3);
    strcpy(temp, intal2);
    tmp = intal_diff(temp2, intal1);
    if (intal_compare(tmp, "10000") != 1) {
      free(tmp);
      break;
    } else free(tmp);
    while (intal_compare(temp2, intal1) != 1) {
      strcpy(temp3, temp2);
      tmp = intal_add(temp2, temp);
      strcpy(temp2, tmp);
      free(tmp);
      tmp = intal_multiply(temp, "2");
      strcpy(temp, tmp);
      free(tmp);
      ++b;
    }
  }
  strcpy(temp, intal2);
  strcpy(temp2, temp3);
  while (intal_compare(temp2, intal1) != 1) {
    strcpy(temp3, temp2);
    tmp = intal_add(temp2, temp);
    strcpy(temp2, tmp);
    free(tmp);
    ++b;
  }
  tmp = intal_diff(temp3, intal1);
  strcpy(temp2, tmp);
  free(tmp);
  free(temp);
  free(temp3);
  if (intal_compare(temp2, intal2) == 0) {
    strcpy(temp2, "0");
    return temp2;
  } else {
    return temp2;
  }
}
char * intal_pow(const char * intal1, unsigned int n) {
  if (strcmp(intal1, "1") == 0) {
    char * ans = malloc(sizeof(char) * 2);
    ans[0] = 48;
    ans[1] = '\0';
    return ans;
  }
  if (n == 0) {
    char * ans = malloc(sizeof(char) * 2);
    ans[0] = 49;
    ans[1] = '\0';
    return ans;
  }
  int l1 = strlen(intal1);
  int i = 0;
  char * temp = malloc(sizeof(char) * 2000);
  char * tmp;
  if (n == 1) {
    char * ans = malloc(sizeof(char) * (1 + l1));
    strcpy(ans, intal1);
    return ans;
  }
  strcpy(temp, intal1);
  for (i = 0; i < n - 1; ++i) {
    tmp = intal_multiply(temp, intal1);
    strcpy(temp, tmp);
    free(tmp);
  }
  return temp;
}
char * intal_gcd(const char * intal1,
  const char * intal2) {
  int l2 = strlen(intal2);
  if (strcmp(intal1, "0") == 0 && strcmp(intal2, "0") == 0) {
    char * ans = malloc(sizeof(char) * 2);
    ans[0] = 48;
    ans[1] = '\0';
    return ans;
  }
  int l1 = strlen(intal1);
  if (strcmp(intal1, "0") == 0 || intal_compare(intal1, intal2) == 0) {
    char * ans = malloc(sizeof(char) * (1 + l2));
    strcpy(ans, intal2);
    return ans;
  }
  if (strcmp(intal2, "0") == 0) {
    char * ans = malloc(sizeof(char) * (1 + l1));
    strcpy(ans, intal1);
    return ans;
  }
  return intal_gcd(intal_mod(intal2, intal1), intal1);
}

char * intal_fibonacci(unsigned int n) {
  if (n == 0) {
    char * ans = malloc(sizeof(char) * 2);
    ans[0] = 48;
    ans[1] = '\0';
    return ans;
  }
  unsigned int i = 0;
  char * tmp;
  char * one = malloc(sizeof(char) * 1005);
  strcpy(one, "0");
  char * two = malloc(sizeof(char) * 1005);
  strcpy(two, "1");
  for (i = 2; i <= n; ++i) {
    tmp = intal_add(one, two);
    strcpy(one, two);
    strcpy(two, tmp);
    free(tmp);
  }
  free(one);
  return two;
}

char * intal_factorial(unsigned int n) {
  if (n < 2) {
    char * ans = malloc(sizeof(char) * 2);
    ans[0] = 49;
    ans[1] = '\0';
    return ans;
  }
  char * ans = malloc(sizeof(char) * 1005);
  strcpy(ans, "1");
  char * tmp;
  char * cou = malloc(sizeof(char) * 1005);
  strcpy(cou, "2");
  char * num = malloc(sizeof(char) * 1005);
  sprintf(num, "%u", n);
  while (1) {
    if (intal_compare(cou, num) == 1) {
      break;
    }
    tmp = intal_multiply(ans, cou);
    strcpy(ans, tmp);
    free(tmp);
    tmp = intal_add("1", cou);
    strcpy(cou, tmp);
    free(tmp);
  }
  free(num);
  free(cou);
  return ans;
}

static unsigned int min(unsigned int a, unsigned int b) {
  if (a < b) return a;
  else return b;
}

char * intal_bincoeff(unsigned int n, unsigned int k){
  if (n == 0) {
    char * ans = malloc(sizeof(char) * 2);
    ans[0] = 48;
    ans[1] = '\0';
    return ans;
  }
  char ** ans = (char ** ) malloc((k + 1) * sizeof(char * ));
  unsigned int i = 0;
  for (i = 0; i < (k + 1); ++i) ans[i] = (char * ) malloc(1001 * sizeof(char));
  unsigned int j = 0;
  char * tmp;
  for (i = 0; i < (k + 1); ++i) strcpy(ans[i], "0");
  strcpy(ans[0], "1");
  for (i = 1; i <= n; ++i) {
    for (j = min(i, k); j > 0; --j) {
      tmp = intal_add(ans[j], ans[j - 1]);
      strcpy(ans[j], tmp);
      free(tmp);
    }
  }
  char * ans2 = malloc(sizeof(char) * 1001);
  strcpy(ans2, ans[k]);
  for (i = 0; i < (k + 1); ++i) free(ans[i]);
  free(ans);
  return ans2;
}

int intal_max(char ** arr, int n) {
  if (n < 1) {
    return 0;
  }
  int tmp = 0;
  int i = 0;
  for (i = 0; i < n; ++i) {
    if (intal_compare(arr[i], arr[tmp]) == 1) tmp = i;
  }
  return tmp;
}

int intal_min(char ** arr, int n) {
  if (n < 1) {
    return 0;
  }
  int tmp = 0;
  int i = 0;
  for (i = 0; i < n; ++i) {
    if (intal_compare(arr[i], arr[tmp]) == -1) tmp = i;
  }
  return tmp;
}

int intal_search(char ** arr, int n,
  const char * key) {
  if (n < 1) {
    return 0;
  }
  int i = 0;
  for (i = 0; i < n; ++i) {
    if (intal_compare(arr[i], key) == 0) return i;
  }
  return -1;
}

int intal_binsearch(char ** arr, int n,
  const char * key) {
  if (n < 1) {
    return 0;
  }
  int m = 0;
  int l = 0;
  int r = n;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (intal_compare(arr[m], key) == 0) return m;
    if (intal_compare(arr[m], key) == -1) l = m + 1;
    else r = m - 1;
  }
  return -1;
}

static void swap(int a, int b, char ** arr) {
  char temp[1001] = {
    0
  };
  strcpy(temp, arr[a]);
  strcpy(arr[a], arr[b]);
  strcpy(arr[b], temp);
}

static int partition(char ** arr, int low, int high) {
  char * pivot = malloc(sizeof(char) * 1001);
  strcpy(pivot, arr[high]);
  int i = (low - 1);
  int j = 0;
  for (j = low; j <= high - 1; ++j) {
    if (intal_compare(arr[j], pivot) == -1) {
      ++i;
      swap(i, j, arr);
    }
  }
  swap(i + 1, high, arr);
  free(pivot);
  return (i + 1);
}

static void quickSort(char ** arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void intal_sort(char ** arr, int n) {
  quickSort(arr, 0, n - 1);
}

char * coin_row_problem(char ** arr, int n) {
  int i = 0;
  char ans[4][1001] = {
    0
  };
  strcpy(ans[0], "0");
  strcpy(ans[1], arr[0]);
  char * tmp;
  for (i = 2; i <= n; i++) {
    tmp = intal_add(arr[i - 1], ans[0]);
    if (intal_compare(tmp, ans[1]) == 1) {
      strcpy(ans[2], tmp);
    } else {
      strcpy(ans[2], ans[1]);
    }
    strcpy(ans[0], ans[1]);
    strcpy(ans[1], ans[2]);
    free(tmp);
  }
  char * ans2 = malloc(sizeof(char) * 1001);
  strcpy(ans2, ans[2]);
  return ans2;
}
