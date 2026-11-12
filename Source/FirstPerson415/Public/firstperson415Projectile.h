// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "firstperson415Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS(config=Game)
class Afirstperson415Projectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component*/
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ballMesh;

	UPROPERTY(EditAnywhere)
	UMaterial* baseMat;

	UPROPERTY()
	FLinearColor randColor;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* projMat;

	UPROPERTY()
	UMaterialInstanceDynamic* dmiMat;


public:
	// Sets default values for this actor's properties
	Afirstperson415Projectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay();

public:
	/** called when projectile hits something*/
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OPtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }


};
