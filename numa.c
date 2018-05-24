#include <stdio.h>
#include <numa.h>

int main(void)
{
 struct bitmask* bm;
 struct nodemask_t* nm;
 int numa_max_node_;


/*
 printf("%d\n", numa_max_node());

 printf("%ld\n", numa_node_size(0, NULL));
 printf("%ld\n", numa_node_size(2, NULL));
*/

 printf("numa_num_configured_nodes(): %d\n", numa_num_configured_nodes()); // 2 

 numa_max_node_ = numa_max_node();
 printf("numa_max_node(): %d\n", numa_max_node_); // 

 printf("-- numa_get_membind()\n");
 bm = numa_get_membind();
// printf("numa_get_membind(): %ld\n", bm->size);
 for (int i = 0; i < numa_max_node_; i++)
   if (numa_bitmask_isbitset(bm, i)) 
     printf("node%d is available\n", i);

 printf("-- numa_get_mems_allowed()\n");
 bm = numa_get_mems_allowed();
// printf("numa_get_membind(): %ld\n", bm->size);
 for (int i = 0; i < numa_max_node_; i++)
   if (numa_bitmask_isbitset(bm, i)) 
     printf("node%d is available\n", i);

 printf("-- numa_all_nodes_ptr\n");
 for (int i = 0; i < numa_max_node_; i++)
   if (numa_bitmask_isbitset(numa_all_nodes_ptr, i)) 
     printf("node%d is available\n", i);

 printf("-- numa_nodes_ptr\n");
 for (int i = 0; i <= numa_max_node_; i++)
   if (numa_bitmask_isbitset(numa_nodes_ptr, i)) 
     printf("node%d is available\n", i);

//   printf("[%d]: 0x%lx\n", i, bm->maskp[i]);


 size_t parts = 0;

/*
 printf("%d\n", numa_num_task_nodes());
 printf("%d\n", numa_num_task_cpus());
 printf("%d\n", numa_max_possible_node());
 printf("%d\n", numa_num_possible_nodes());
 printf("%d\n", numa_num_configured_nodes());
 numa_bitmask_isbitset(bm, 0);
 bm = numa_get_membind();

 for (int i = 0; i < numa_max_node(); i++)
   if (numa_bitmask_isbitset(bm, i))
     printf("node%d can be binded\n", i); 

 for (int i = 0; i < numa_max_node() + 1; i++)
   if (numa_bitmask_isbitset(numa_all_nodes_ptr, i))
     printf("node%d can be binded\n", i); 

 for (int i = 0; i < numa_max_node() + 1; i++)
   if (numa_bitmask_isbitset(numa_nodes_ptr, i))
     printf("node%d can be binded\n", i); 

  printf("numa_max_possible_node():   %d\n", numa_max_possible_node());
  printf("numa_num_possible_nodes():  %d\n", numa_num_possible_nodes());
  printf("numa_max_node():            %d\n", numa_max_node());
  printf("numa_num_configured_nodes():  %d\n", numa_num_configured_nodes());
  printf("numa_num_task_nodes():  %d\n", numa_num_task_nodes());
*/
 
 bm = numa_get_membind();

 int i; 
 printf("bm->size=%lx\n", bm->size);
 for (i = 0; i < bm->size / (8 * sizeof(unsigned long)); i++) {
   printf(" - %#.16lx\n", bm->maskp[i]);
 }
   
}
