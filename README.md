# c_garbage_collector

[![.github/workflows/norminette.yml](https://github.com/c3b5aw/c_garbage_collector/actions/workflows/norminette.yml/badge.svg)](https://github.com/c3b5aw/c_garbage_collector/actions/workflows/norminette.yml) <br />
[![.github/workflows/tests.yml](https://github.com/c3b5aw/c_garbage_collector/actions/workflows/tests.yml/badge.svg)](https://github.com/c3b5aw/c_garbage_collector/actions/workflows/tests.yml) <br />
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/7b6aa479070d45b8b25efe4226d8d7f5)](https://www.codacy.com/gh/c3b5aw/c_garbage_collector/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=c3b5aw/c_garbage_collector&amp;utm_campaign=Badge_Grade)

## usage

```C
#include "includes/gcollector.h

int	main(void)
{
	void	*ptr;

	ptr = galloc(100);
	gfree(ptr);
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
bool	gfree(void **ptr);
void	*galloc(size_t size);
```

### published methods
```C
t_hashtable	*gc_new(unsigned int size);
bool		gc_destroy(void);
t_hashtable	**gc_anchor(void);
bool		gc_anchor_exist(void);
```