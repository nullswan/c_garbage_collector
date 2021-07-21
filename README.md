# c_garbage_collector

[![.github/workflows/norminette.yml](https://github.com/c3b5aw/c_garbage_collector/actions/workflows/norminette.yml/badge.svg)](https://github.com/c3b5aw/c_garbage_collector/actions/workflows/norminette.yml) <br />
[![.github/workflows/tests.yml](https://github.com/c3b5aw/c_garbage_collector/actions/workflows/tests.yml/badge.svg)](https://github.com/c3b5aw/c_garbage_collector/actions/workflows/tests.yml) <br />
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/7b6aa479070d45b8b25efe4226d8d7f5)](https://www.codacy.com/gh/c3b5aw/c_garbage_collector/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=c3b5aw/c_garbage_collector&amp;utm_campaign=Badge_Grade)

## usage

```C
#include "includes/gcollector.h"

int	main(void)
{
	void	*ptr;

	// gc_new(100); - gc malloc bucket environnement start size
	ptr = galloc(100);
	// ptr = 0xMEMADDR;
	gfree(ptr);
	// ptr = 0;
	for (int i = 0; i < 100; i++)
		ptr = galloc(100);
	gc_destroy();
}

int	main(void)
{
	void	*ptr;

	// gc_new(100); - gc malloc bucket environnement start size
	ptr = galloc(100);
	// ptr = 0xMEMADDR;
	gree(ptr);
	// ptr = 0xMEMADDR;
	for (int i = 0; i < 100; i++)
		ptr = galloc(100);
	gc_destroy();
}
```

### required header
```C
#include "includes/gcollector.h"
```

### data types
```C
view_hashtable
```

### default methods
```C
// free mem, destroy node and set *ptr to 0.
bool	gfree(void **ptr);

// free mem, destroy node.
bool	gree(void *ptr);

// allocate mem, create node.
void	*galloc(size_t size);
```

### published methods
```C
t_hashtable	*gc_new(unsigned int size);
bool		gc_destroy(void);
t_hashtable	**gc_anchor(void);
bool		gc_anchor_exist(void);
```