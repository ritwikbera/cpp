#include <torch/torch.h>
#include <bits/stdc++.h>

using namespace std;

constexpr double kLearningRate = 0.001;
constexpr int kMaxIterations = 100000;

void native_run(double minimal){

    auto x = torch::randn({1,1}, torch::requires_grad(true));

    for (size_t t = 0; t < kMaxIterations; t++){
        auto y = (x - minimal) * (x - minimal);
        if (y.item<double>() < 1e-3){
            break;
        }

        y.backward();

        torch::NoGradGuard no_grad_guard;
        x -= kLearningRate * x.grad();

        // x.grad().reset();
    }

    cout << "[native] Actual minimal x value: " << minimal <<
        ", calculated optimal x value: " << x.item<double>() << endl;
}
int main(int argc, char const *argv[])
{
    /* code */
    native_run(atof(argv[1]));
    return 0;
}