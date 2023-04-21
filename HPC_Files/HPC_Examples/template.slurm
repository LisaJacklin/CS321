#!/bin/bash

#SBATCH --job-name="Template"
#SBATCH --partition=debug
#SBATCH --ntasks=24
#SBATCH --tasks-per-node=24
#SBATCH --time=00:30:00
#SBATCH --mail-user=email@example.edu
#SBATCH --mail-type=BEGIN
#SBATCH --mail-type=END
#SBATCH --mail-type=FAIL
#SBATCH --output="Template.%j"

module list

#Purge and Load Modules
module purge
module load slurm

start=`date +%s`
echo "Hello World"
echo $SLURM_NODELIST
end=`date +%s`
echo $((end-start))
