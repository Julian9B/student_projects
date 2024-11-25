# Staircase designer

## 1. About

This .NET Maui exercise is about creating a window app that can design a staircase, based on user input data.

## 2. Code

We base our code on previous Staircase Designer console app. However, we use XAML for frontend and C# for codebehind instead od using C++.

### 2.1. XAML file

In the 'MainPage.xaml' file we have two entries, which serve as user input, as well as button to trigger the function. Below it, there is a label, in which we are going to display the result of calculation.

```xaml
<VerticalStackLayout Padding="30,0" Spacing="25" HorizontalOptions="Center" VerticalOptions="Center">
    
    <Label Text="Welcome to Staircase Designer!" Style="{StaticResource Headline}" SemanticProperties.HeadingLevel="Level1" />
    <Label Text="Just enter overall height and length of your planned staircase and let us do the rest!" />

    <!-- input of overall height -->
    <Entry Keyboard="Numeric" TextChanged="OverallHeightEntry_TextChanged" MaxLength="20" Placeholder="Staircase height [m]" />

    <!-- input of overall length -->
    <Entry Keyboard="Numeric" TextChanged="OverallLengthEntry_TextChanged" MaxLength="20" Placeholder="Staircase length [m]" />

    <Button Text="Calculate" Clicked="Calculate_Clicked" />

    <!-- output -->
    <Label x:Name="resultLabel" />

</VerticalStackLayout>
```

### 2.2. C# file

All of the logic is executed in 'MainPage.xaml.cs' file. We have 3 event handlers: one for changing text of each entry (which update 'heightOverall' and 'lengthOverall' variables) and one for clicking the button, which triggers 'CalculateStaircase' function. This function returns bool, telling whether or not the staircase with given dimensions is possible to build. It also has reference to variables such as 'stepsNumber', 'stepHeight' and 'stepDepth', which are changed inside function, if it returns true. To tell if ergonomic staircase is possible, the function calculates heightOverall to lengthOverall ratio and checks if it fits inside hardcoded range for ergonomic staircase.

```C#
double heightOverall;
double lengthOverall;


private bool CalculateStaircase(double heightOverall, double lengthOverall, ref int stepsNumber, ref double stepHeight, ref double stepDepth)
{

    double ratio = heightOverall / lengthOverall;
    double minRatio = 0.5;
    double maxRatio = 0.9;

    bool possible = ratio <= maxRatio && ratio >= minRatio; // 0.7 is the best ratio

    if (possible) // if staircase is possible to build, calculate output
    {

        double perfectStepHeight = 20;
        double unroundedStepsNumber = (heightOverall * 100) / perfectStepHeight;

        stepsNumber = (int) Math.Round(unroundedStepsNumber);
        stepHeight = Math.Round((heightOverall * 100) / stepsNumber, 1);
        stepDepth = Math.Round((lengthOverall * 100) / (stepsNumber - 1), 1);
    }

    return possible;
}


// if user clicks the button
private void Calculate_Clicked(object sender, EventArgs e)
{
    int stepsNumber = 0;
    double stepHeight = 0;
    double stepDepth = 0;

    if (CalculateStaircase(heightOverall, lengthOverall, ref stepsNumber, ref stepHeight, ref stepDepth)) // if the staircase is possible to build (calls the function at the same time)
    {
        resultLabel.Text = $"Number of steps: {stepsNumber}\nHeight of each step: {stepHeight}cm\nDepth of each step: {stepDepth}cm"; // change text of output label
    }
    else
    {
        resultLabel.Text = "Sorry, it is impossible to create ergonomic staircase using dimensions given by you."; // change text of output label
    }
}


// if user changes text of height entry
private void OverallHeightEntry_TextChanged(object sender, TextChangedEventArgs e)
{
    heightOverall = double.Parse(((Entry)sender).Text);
}


// if user changes text of length entry
private void OverallLengthEntry_TextChanged(object sender, TextChangedEventArgs e)
{
    lengthOverall = double.Parse(((Entry)sender).Text);
}
```

## 3. Result

...

## 4. Conclusion

...

You can see the first SD as console app [here](https://github.com/Julian9B/student_projects/tree/main/cpp/staircase-designer).

## Authors

[Julian9B](https://github.com/Julian9B)
