using System;

namespace BackPropagation
{
    class Program
    {
        static void Main(string[] args)
        {
            train();
        }

        class sigmoid
        {
            public static double output(double x)
            {
                return 1.0 / (1.0 + Math.Exp(-x));
            }

            public static double derivative(double x)
            {
                return x * (1 - x);
            }
        }
        class OutputNeuron
        {
            public double[] inputs = new double[2];
            public double[] weights = new double[2];
            public double error;

            private double biasWeight;

            private Random r = new Random();

            public double output
            {
                get { return sigmoid.output(weights[0] * inputs[0] + weights[1] * inputs[1] + biasWeight); }
            }

            public void randomizeWeights()
            {
                weights[0] = r.NextDouble();
                weights[1] = r.NextDouble();
                biasWeight = r.NextDouble();
            }

            public void adjustWeights()
            {
                weights[0] += error * inputs[0];
                weights[1] += error * inputs[1];
                biasWeight += error;
            }
        }

        class Neuron
        {
            public double input;
            public double weight;
            public double error;

            private double biasWeight;

            private Random r = new Random();

            public double output
            {
                get { return sigmoid.output(weight * input + biasWeight); }
            }

            public void randomizeWeights()
            {
                weight = r.NextDouble();
                biasWeight = r.NextDouble();
            }

            public void adjustWeights()
            {
                weight += error * input;
                biasWeight += error;
            }
        }

        private static void train()
        {
            // the input values
            double[] inputs = { 0.10, 0.06, 0.25, 0.16, 0.81, 1f, 0.36, 0.49, 0.01, 0.04, 1.21, 1.44, 1.69 };

            // desired results
            double[] results = { 0.023026, 0.0179176, 0.03218876, 0.0277259, 0.0439445, 0.0460517, 0.035835189, 0.03891820298, 0, 0.0138629, 0.04795791, 0.049698133, 0.05129899 };

            // creating the neurons
            Neuron N1 = new Neuron();
            Neuron N2 = new Neuron();
            OutputNeuron O1 = new OutputNeuron();
            OutputNeuron O2 = new OutputNeuron();
            OutputNeuron Output = new OutputNeuron();

            // random weights
            N1.randomizeWeights();
            N2.randomizeWeights();
            O1.randomizeWeights();
            O2.randomizeWeights();
            Output.randomizeWeights();

            int epoch = 0;

        Retry:
            epoch++;
            for (int i = 0; i < 13; i++)  // very important, do NOT train for only one example
            {
                // 1) forward propagation (calculates output)
                N1.input = inputs[i];
                N2.input = inputs[i];
                O1.inputs[0] = N1.output;
                O1.inputs[1] = N2.output;
                O2.inputs[0] = N1.output;
                O2.inputs[1] = N2.output;
                Output.inputs[0] = O1.output;
                Output.inputs[1] = O2.output;


                Console.WriteLine("Entrada: {0} Salida: {1}", 100 * N1.input, 100 * Output.output);

                // 2) back propagation (adjusts weights)

                // adjusts the weight of the output neuron, based on its error
                Output.error = sigmoid.derivative(Output.output) * (results[i] - Output.output);
                Output.adjustWeights();

                // then adjusts the hidden neurons' weights, based on their errors
                O1.error = sigmoid.derivative(O1.output) * O1.error * ((Output.weights[0] + Output.weights[1]) / 2);
                O2.error = sigmoid.derivative(O2.output) * O2.error * ((Output.weights[0] + Output.weights[1]) / 2);
                N1.error = sigmoid.derivative(N1.output) * N1.error * ((O1.weights[0] + O1.weights[1]) / 2);
                N2.error = sigmoid.derivative(N2.output) * O2.error * ((O2.weights[0] + O2.weights[1]) / 2);

                N1.adjustWeights();
                N2.adjustWeights();
                O1.adjustWeights();
                O2.adjustWeights();
                Output.adjustWeights();
            }

            if (epoch < 200000)
                goto Retry;

            Console.ReadLine();
            bool salir = false;
            while (salir == false)
            {
                Console.WriteLine("Introduzca una entrada:");
                float entrada = Convert.ToSingle(Console.ReadLine());
                N1.input = entrada / 100;
                N2.input = entrada / 100;

                O1.inputs[0] = N1.output;
                O1.inputs[1] = N2.output;

                O2.inputs[0] = N1.output;
                O2.inputs[1] = N2.output;

                Output.inputs[0] = O1.output;
                Output.inputs[1] = O2.output;
                Console.WriteLine("Salida: " + 100 * Output.output);
            }
        }
    }
}
