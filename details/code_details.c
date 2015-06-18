int main(void)
{
    FILE *file;
    int i = 0;

    file = fopen("testcases.txt", "r");

    while (EOF != fscanf(file, "%c %6s %c", &carinfo[i].street_name,
                                            &carinfo[i].number_plate, 
                                            &carinfo[i].destination))
    {
        printf("Loop #%d\n", i+1);
        i++;
    }

    for (i = 0; i < 9; i++)
    {
        printf("Street Name: %c, Number Plate: %s, Destination: %c\n", carinfo[i].street_name, 
                                                                       carinfo[i].number_plate, 
                                                                       carinfo[i].destination);
    }

    fclose(file);
    return 0;
}
