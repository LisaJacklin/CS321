#!/bin/bash

#SBATCH --job-name="Parallel Processes"
#SBATCH --partition=debug
#SBATCH --ntasks=24
#SBATCH --tasks-per-node=24
#SBATCH --time=00:30:00
#SBATCH --mail-user=email@example.edu
#SBATCH --mail-type=BEGIN
#SBATCH --mail-type=END
#SBATCH --mail-type=FAIL
#SBATCH --output="ParallelProcess.%j"

module list

#Purge and Load Modules
module purge
module load slurm
module load foss/2022a
module load Python/3.10.4

cd $SLURM_SUBMIT_DIR
start=`date +%s`
for i in `seq -w 0 19`
do
    python ./src/rotX.py ./data/random.$i ./output/output.$i 8 &
done
wait
for i in `seq -w 0 19`
do
    cat ./output/output.$i >> ./output/final_output
done
echo $SLURM_NODELIST
end=`date +%s`
echo $((end-start))
