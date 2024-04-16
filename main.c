#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  * main - Entry point
 *   * @argc: Argument count
 *    * @argv: Argument vector
 *     * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 *      */
int main(int argc, char *argv[])
{
	    if (argc != 2)
		        {
				        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
					        exit(EXIT_FAILURE);
						    }

	        FILE *file = fopen(argv[1], "r");
		    if (file == NULL)
			        {
					        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
						        exit(EXIT_FAILURE);
							    }

		        stack_t *stack = NULL;
			    char *line = NULL;
			        size_t len = 0;
				    ssize_t read;
				        unsigned int line_number = 0;

					    while ((read = getline(&line, &len, file)) != -1)
						        {
								        line_number++;
									        char *opcode = strtok(line, " \t\n");
										        char *arg = strtok(NULL, " \t\n");

											        if (opcode == NULL || (strcmp(opcode, "push") == 0 && arg == NULL))
													        {
															            fprintf(stderr, "L%d: usage: push integer\n", line_number);
																                exit(EXIT_FAILURE);
																		        }

												        if (strcmp(opcode, "push") == 0)
														        {
																            int value = atoi(arg);
																	                _push(&stack, value);
																			        }
													        else if (strcmp(opcode, "pall") == 0)
															        {
																	            _pall(stack);
																		            }
														        else
																        {
																		            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
																			                exit(EXIT_FAILURE);
																					        }
															    }

					        fclose(file);
						    if (line)
							        {
									        free(line);
										    }

						        return EXIT_SUCCESS;
}

