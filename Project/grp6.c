#include <stdio.h>

#define PIECES_PER_DOZEN 12

int main()
{
    float buyprice, sellingprice;
    int quantitySold;

    printf("Enter the buying price per unit: ");
    scanf("%f", &buyprice);
    printf("Enter the selling price per uint: ");
    scanf("%f", &sellingprice);
    printf("Enter quatity sold: ");
    scanf("%d", &quantitySold);

       float totalBuyingPrice = buyprice * quantitySold;

    int dozens = quantitySold / PIECES_PER_DOZEN;
    int remainingPieces = quantitySold % PIECES_PER_DOZEN;

    float totalSellingPrice;

    if (dozens > 0)
    {
        // Apply discount of 3% for each dozen

        float discount = 0.03 * sellingprice * PIECES_PER_DOZEN * dozens;
        totalSellingPrice = (sellingprice * quantitySold) - discount;
    }
    else
    {
        totalSellingPrice = sellingprice * quantitySold;
    }
    float profit = totalSellingPrice - totalBuyingPrice;

    printf("\n=== Profit/Loss Calculation ===\n");
    printf("Buying Price: %.2f\n", totalBuyingPrice);
    printf("Selling Price: %.2f\n", totalSellingPrice);
    printf("Profit/Loss: %.2f\n", profit);
}