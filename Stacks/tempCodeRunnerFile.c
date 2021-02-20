                return 0;
            }

            else if(!isMatchingPair(pop(&stack), exp[j]))
            {
                return 0;
            }
        }
        j++;
    }

    if(stack==NULL)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}