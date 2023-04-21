#!/bin/bash

#SBATCH --job-name="Serial Processes"
#SBATCH --partition=debug
#SBATCH --ntasks=24
#SBATCH --tasks-per-node=24
#SBATCH --time=00:30:00
#SBATCH --mail-user=email@example.edu
#SBATCH --mail-type=BEGIN
#SBATCH --mail-type=END
#SBATCH --mail-type=FAIL
#SBATCH --output="SerialProcess.%j"

module list

#Purge and Load Modules
module purge
module load slurm
module load foss/2022a
module load Python/3.10.4

start=`date +%s`
python ./src/rotX.py ./data/random.txt ./output/random_rot8.txt 8
echo $SLURM_NODELIST
end=`date +%s`
echo $((end-start))
