#!/bin/bash

#SBATCH --job-name="OMP Hello"
#SBATCH --partition=debug
#SBATCH --ntasks=24
#SBATCH --tasks-per-node=24
#SBATCH --time=00:30:00
#SBATCH --mail-user=email@example.edu
#SBATCH --mail-type=BEGIN
#SBATCH --mail-type=END
#SBATCH --mail-type=FAIL
#SBATCH --output="OMP_hello.%j"

module list

#Purge and Load Modules
module purge
module load slurm
module load foss/2022a

start=`date +%s`
./bin/hello
end=`date +%s`
echo $((end-start))
