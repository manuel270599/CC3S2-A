package org.example;

import org.junit.jupiter.api.Test;
import static org.assertj.core.api.Assertions.assertThat;

class MoneyTest {
    //prueba simple con 2 valores un entero y string
    @Test
    void constructorShouldSetAmountAndCurrency() {
        // Arrange
        int expectedAmount = 100;
        String expectedCurrency = "USD";
        // Act
        Money money = new Money(expectedAmount, expectedCurrency);
        // Assert
        assertThat(money.getAmount()).isEqualTo(expectedAmount);
        assertThat(money.getCurrency()).isEqualTo(expectedCurrency);
    }

}
