#include <stdio.h>

#define PIECES_PER_DOZEN 12

int main()
{
    float buyingPrice, sellingPrice;
    int quantitySold;

    printf("Enter the buying price per unit: ");
    scanf("%f", &buyingPrice);

    printf("Enter the selling price per unit: ");
    scanf("%f", &sellingPrice);

    printf("Enter the quantity sold: ");
    scanf("%d", &quantitySold);

    float totalBuyingPrice = buyingPrice * quantitySold;

    int dozens = quantitySold / PIECES_PER_DOZEN;
    int remainingPieces = quantitySold % PIECES_PER_DOZEN;

    float totalSellingPrice;
    if (dozens > 0)
    {
        // Apply discount of 3% for each dozen
        float discount = 0.03 * sellingPrice * PIECES_PER_DOZEN * dozens;
        totalSellingPrice = (sellingPrice * quantitySold) - discount;
    }
    else
    {
        totalSellingPrice = sellingPrice * quantitySold;
    }

    float profit = totalSellingPrice - totalBuyingPrice;

    printf("\n=== Profit/Loss Calculation ===\n");
    printf("Buying Price: %.2f\n", totalBuyingPrice);
    printf("Selling Price: %.2f\n", totalSellingPrice);
    printf("Profit/Loss: %.2f\n", profit);

    return 0;
}
