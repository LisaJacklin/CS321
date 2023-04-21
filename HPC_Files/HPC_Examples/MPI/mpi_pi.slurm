#!/bin/bash

#SBATCH --job-name="MPI Pi"
#SBATCH --partition=debug
#SBATCH --ntasks=48
#SBATCH --tasks-per-node=24
#SBATCH --time=00:30:00
#SBATCH --mail-user=email@example.edu
#SBATCH --mail-type=BEGIN
#SBATCH --mail-type=END
#SBATCH --mail-type=FAIL
#SBATCH --output="MPI_Pi.%j"

module list

#Purge and Load Modules
module purge
module load slurm
module load foss/2022a

start=`date +%s`
srun -l /bin/hostname | sort -n | awk '{print $2}' > ./nodes.$SLURM_JOB_ID
mpirun -np $SLURM_NTASKS -machinefile ./nodes.$SLURM_JOB_ID ./bin/mpireducepi
echo $SLURM_NODELIST
end=`date +%s`
echo $((end-start))
